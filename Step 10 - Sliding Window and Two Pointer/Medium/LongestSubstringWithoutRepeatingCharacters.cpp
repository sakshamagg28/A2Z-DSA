class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);

        int l = 0, r = 0, maxLen = 0;

        while (r < s.size()){
            if (hash[s[r]] != -1){
                l = max(hash[s[r]] + 1, l);
            }
            maxLen = max(maxLen, r-l+1);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};