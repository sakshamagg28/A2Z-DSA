class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;

        for (char c : num) {

            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }

            st.push(c);
        }

        // Remove remaining digits from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Convert stack to string
        string ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int i = 0;
        while (i < ans.size() && ans[i] == '0')
            i++;

        ans = ans.substr(i);

        if (ans.empty())
            return "0";

        return ans;
    }
};




// Optimized version using string as a stack
class Solution {
public:
    string removeKdigits(string num, int k) {

        string st;

        for (char c : num) {

            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }

            st.push_back(c);
        }

        // Remove remaining digits from the end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;
        while (i < st.size() && st[i] == '0')
            i++;

        st = st.substr(i);

        if (st.empty())
            return "0";

        return st;
    }
};