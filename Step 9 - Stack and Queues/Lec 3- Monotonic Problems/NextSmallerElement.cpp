class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        // Your code goes here
        vector<int> result(arr.size(), -1);
        stack<int> st;

        for (int i = arr.size()-1; i >= 0; i--){

            while (!st.empty() && st.top() >= arr[i]){
                st.pop();
            }

            if (!st.empty()){
                result[i] = st.top();
            }

            st.push(arr[i]);
        }
        return result;
    }
};
