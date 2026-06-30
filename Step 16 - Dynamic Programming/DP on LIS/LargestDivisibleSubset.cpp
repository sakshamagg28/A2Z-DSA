// Method : DP + Parent Array
// State : dp[i] = Largest Divisible Subset ending at i
// Time : O(N²)
// Space : O(N)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> parent(n);

        int maxi = 1;
        int lastIdx = 0;

        for (int i = 0; i < n; i++){
            parent[i] = i;

            for (int prev = 0; prev < i; prev++){
                if (nums[i] % nums[prev] == 0 && dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev] + 1;
                    parent[i] = prev;
                }
            }

            if (dp[i] > maxi){
                maxi = dp[i];
                lastIdx = i;
            }
        }

        vector<int> ans;

        while (parent[lastIdx] != lastIdx){
            ans.push_back(nums[lastIdx]);
            lastIdx = parent[lastIdx];
        }

        ans.push_back(nums[lastIdx]);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};