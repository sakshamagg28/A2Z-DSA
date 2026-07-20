// Method: Hash Map + Rearrangement
// Time: O(n * d)  (d = number of digits, <=10)
// Space: O(n)
// Standard Interview Solution

class Solution {
public:
    const int MOD = 1e9 + 7;

    int rev(int x) {
        int ans = 0;
        while (x) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int, long long> mp;
        long long ans = 0;

        for (int num : nums) {
            int key = num - rev(num);

            ans = (ans + mp[key]) % MOD;
            mp[key]++;
        }

        return ans;
    }
};