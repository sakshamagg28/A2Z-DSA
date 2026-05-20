class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for (auto& p : mp){
            if (p.second != 0){
                return false;
            }
        }
        return true;
    }
};