// Method: Prefix Sum + Hash Map
// Time: O(n)
// Space: O(n)
// Standard Interview Solution

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;   // prefixSum -> first index

        int prefixSum = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += (nums[i] == 0 ? -1 : 1);

            if (mp.count(prefixSum)) {
                ans = max(ans, i - mp[prefixSum]);
            } else {
                mp[prefixSum] = i;
            }
        }

        return ans;
    }
};