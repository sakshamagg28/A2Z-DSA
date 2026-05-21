class Solution {
public:
    bool isPalindrome(string &s, int left, int right){
        while (left < right){
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;

        int n = s.size();

        int maxLen = 0;
        int maxStart;

        for (int i=0; i<n; i++){   
            for (int j=n-1; j>=0; j--){
                int len = j-i+1;

                if (len <= maxLen) break;

                if (isPalindrome(s, i, j)){
                    maxLen = len;
                    maxStart = i;
                    break;
                }
            }
        }
        return s.substr(maxStart, maxLen);
    }
};