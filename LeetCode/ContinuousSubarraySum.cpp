// Method: Prefix Sum + Modulo + Hash Map
// Time: O(n)
// Space: O(min(n, k))
// Standard Interview Solution

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;   // remainder -> first index

        int prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int rem = prefixSum % k;

            if (mp.count(rem)) {
                if (i - mp[rem] >= 2)
                    return true;
            } else {
                mp[rem] = i;   // store first occurrence only
            }
        }

        return false;
    }
};