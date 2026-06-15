class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for (int a : asteroids){
            if (a > 0) {
                st.push(a);
            }
            else {
                while (!st.empty() && st.top() > 0 && st.top() < abs(a)){
                    st.pop();
                }
                if (st.empty() || st.top() < 0){
                    st.push(a);
                }
                else if (st.top() == abs(a)){
                    st.pop();
                }
            }
        }

        vector<int> ans(st.size());

        for (int i = st.size()-1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};




// My solution
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> result;

        for (int i = n-1; i >= 0; i--){
            if (asteroids[i] < 0) st.push(asteroids[i]);

            else{
        
                while (!st.empty() && asteroids[i] > abs(st.top())){
                    st.pop();
                }
                
                if (!st.empty() && asteroids[i] == abs(st.top())){
                    st.pop();
                }
                else if (st.empty()) result.push_back(asteroids[i]);
            }
            
        }
        stack<int> st2;
        if (!st.empty()){
            while (!st.empty()){
                st2.push(st.top());
                st.pop();
            }
        }
        if (!st2.empty()){
            while (!st2.empty()){
                result.push_back(st2.top());
                st2.pop();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};