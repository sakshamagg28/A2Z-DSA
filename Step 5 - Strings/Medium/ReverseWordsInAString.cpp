class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int write = 0;
        int i = 0;
        int n = s.size();

        while (i < n){
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break;

            if (write > 0) s[write++] = ' ';

            int start = write;
            
            while (i < n && s[i] != ' '){
                s[write++] = s[i++];
            }

            reverse(s.begin() + start, s.begin() + write);
        }
        
        s.resize(write);
        return s;
    }
};