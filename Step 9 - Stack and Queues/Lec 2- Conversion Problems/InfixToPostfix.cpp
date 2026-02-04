class Solution {
public:
    string infixToPostfix(string s) {
        // Your code goes here
        stack<char> st;
        string result = "";

        for (int i = 0; i < s.size(); i++){
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
                result += s[i];
            }
            
            
        }
    }
};