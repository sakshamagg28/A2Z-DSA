class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s){
            if (c == '(' || c == '[' || c == '{'){
                st.push(c);
            }
            else {
                if (st.empty() == true){
                    return false;
                }
                if ((c == ')' && st.top() == '(') || (c == ']' && st.top() == '[') || (c == '}' && st.top() == '{')) st.pop();
                else return false;
            }
        }

        if (st.size() == 0) return true;
        return false;
    }
};