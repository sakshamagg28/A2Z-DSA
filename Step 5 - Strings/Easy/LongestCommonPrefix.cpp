class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for (string& s : strs){
            if (ans.size() > s.size()){
                ans.resize(s.size());
            }
            for (int i = 0; i < s.size(); i++){
                if (s[i] != ans[i]){
                    ans.resize(i);
                    break;
                }
            }
        }
        return ans;
    }
};