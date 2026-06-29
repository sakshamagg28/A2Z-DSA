// Method 1 : Recursion
// State : f(idx,prevIdx)
// Time : Exponential
// Space : O(N)

class Solution {
public:
    int f(int idx, int prevIdx, vector<int>& nums) {

        if (idx == nums.size())
            return 0;

        int notTake = f(idx + 1, prevIdx, nums);

        int take = 0;
        if (prevIdx == -1 || nums[idx] > nums[prevIdx])
            take = 1 + f(idx + 1, idx, nums);

        return max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        return f(0, -1, nums);
    }
};


// Method 2 : Memoization
// State : dp[idx][prevIdx+1]
// Time : O(N²)
// Space : O(N²)

class Solution {
public:
    int f(int idx, int prevIdx, vector<int>& nums, vector<vector<int>>& dp){
        if (idx == nums.size()){
            return 0;
        }

        if (dp[idx][prevIdx + 1] != -1) return dp[idx][prevIdx + 1];

        int notTake = f(idx + 1, prevIdx, nums, dp);

        int take = 0;
        if (prevIdx == -1 || nums[idx] > nums[prevIdx]){
            take = 1 + f(idx + 1, idx, nums, dp);
        }

        return dp[idx][prevIdx + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return f(0, -1, nums, dp);
    }
};


// Method 3 : Tabulation
// State : dp[idx][prevIdx+1]
// Time : O(N²)
// Space : O(N²)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int idx = n - 1; idx >= 0; idx--){
            for (int prevIdx = idx - 1; prevIdx >= -1; prevIdx--){

                int notTake = dp[idx + 1][prevIdx + 1];

                int take = 0;
                if (prevIdx == -1 || nums[idx] > nums[prevIdx]){
                    take = 1 + dp[idx + 1][idx + 1];
                }

                dp[idx][prevIdx + 1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};


// Method 4 : Space Optimized
// State : ahead[prevIdx+1]
// Time : O(N²)
// Space : O(N)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> ahead(n+1, 0);

        for (int idx = n - 1; idx >= 0; idx--){
            vector<int> curr(n+1, 0);

            for (int prevIdx = idx - 1; prevIdx >= -1; prevIdx--){

                int notTake = ahead[prevIdx + 1];

                int take = 0;
                if (prevIdx == -1 || nums[idx] > nums[prevIdx]){
                    take = 1 + ahead[idx + 1];
                }

                curr[prevIdx + 1] = max(take, notTake);
            }

            ahead = curr;
        }

        return ahead[0];
    }
};


// Method 5 : Classic DP
// State : dp[i] = LIS ending at i
// Time : O(N²)
// Space : O(N)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, 1);

        int ans = 1;

        for (int i = 0; i < n; i++) {

            for (int prev = 0; prev < i; prev++) {

                if (nums[prev] < nums[i])
                    dp[i] = max(dp[i], dp[prev] + 1);
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};


// Method 6 : Patience Sorting + Binary Search (Optimal)
// Time : O(NlogN)
// Space : O(N)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> lis;

        for (int num : nums) {

            auto it = lower_bound(
                lis.begin(),
                lis.end(),
                num
            );

            if (it == lis.end())
                lis.push_back(num);
            else
                *it = num;
        }

        return lis.size();
    }
};