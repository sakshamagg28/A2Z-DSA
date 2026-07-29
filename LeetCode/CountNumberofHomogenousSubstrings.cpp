class Solution {
public:
    int countHomogenous(string s) {
        const int MOD = 1e9 + 7;

        int cnt = 1;
        int ans = 0;

        for (int i = 1; i < s.size(); i++){
            if (s[i] == s[i-1]){
                cnt++;
            }
            else{
                ans += ((long long)cnt * (cnt + 1)/2) % MOD;
                cnt = 1;
            }
        }

        ans += ((long long)cnt * (cnt + 1)/2) % MOD;

        return ans;
    }
};