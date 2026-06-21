// Method 1 : Recursion
// State : f(idx,target)
// Time : O(2^N)
// Space : O(N)

class Solution {
public:
    int f(int idx, int target, vector<int>& nums) {

        if (idx == 0) {
            if (target == 0 && nums[0] == 0) return 2;
            if (target == nums[0] || target == -nums[0]) return 1;
            return 0;
        }

        int plus = f(idx - 1, target - nums[idx], nums);
        int minus = f(idx - 1, target + nums[idx], nums);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return f(nums.size() - 1, target, nums);
    }
};



// Method 2 : Memoization
// State : dp[idx][target + offset]
// Time : O(N*TotalSum)
// Space : O(N*TotalSum)
// Special Case : Required because target can become negative

class Solution {
public:
    int f(int idx, int target, vector<int>& nums,
          vector<vector<int>>& dp, int offset) {

        if (idx == 0) {
            if (target == 0 && nums[0] == 0) return 2;
            if (target == nums[0] || target == -nums[0]) return 1;
            return 0;
        }

        if (dp[idx][target + offset] != -1)
            return dp[idx][target + offset];

        int plus = f(idx - 1, target - nums[idx], nums, dp, offset);
        int minus = f(idx - 1, target + nums[idx], nums, dp, offset);

        return dp[idx][target + offset] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > totalSum)
            return 0;

        int n = nums.size();

        vector<vector<int>> dp(
            n,
            vector<int>(2 * totalSum + 1, -1)
        );

        return f(n - 1, target, nums, dp, totalSum);
    }
};



// Method 3 : Subset Sum Transformation + Memoization
// State : dp[idx][target]
// Time : O(N*Target)
// Space : O(N*Target)
// Special Case : Most commonly used interview solution

class Solution {
public:
    int f(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
        if (idx == 0){
            if (target == 0 && nums[0] == 0) return 2;
            if (target == 0 || target == nums[0]) return 1;
            return 0;
        }

        if (dp[idx][target] != -1) return dp[idx][target];

        int notTake = f(idx - 1, target, nums, dp);

        int take = 0;
        if (nums[idx] <= abs(target)){
            take = f(idx - 1, target - nums[idx], nums, dp);
        }

        return dp[idx][target] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum < abs(target)) return 0;
        if ((totalSum - target) % 2 == 1) return 0;
        int req = (totalSum - target)/2;

        vector<vector<int>> dp(n, vector<int>(req + 1, -1));

        return f(n-1, req, nums, dp);
    }
};



// Method 4 : Subset Sum Transformation + Tabulation
// State : dp[idx][target]
// Time : O(N*Target)
// Space : O(N*Target)
// Special Case : Base case changes when nums[0] == 0

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum - target < 0)
            return 0;

        if ((totalSum - target) % 2)
            return 0;

        int req = (totalSum - target) / 2;

        int n = nums.size();

        vector<vector<int>> dp(
            n,
            vector<int>(req + 1, 0)
        );

        if (nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (nums[0] != 0 && nums[0] <= req)
            dp[0][nums[0]] = 1;

        for (int idx = 1; idx < n; idx++) {
            for (int sum = 0; sum <= req; sum++) {

                int notTake = dp[idx - 1][sum];

                int take = 0;
                if (nums[idx] <= sum)
                    take = dp[idx - 1][sum - nums[idx]];

                dp[idx][sum] = take + notTake;
            }
        }

        return dp[n - 1][req];
    }
};



// Method 5 : Subset Sum Transformation + Space Optimized
// State : prev[target]
// Time : O(N*Target)
// Space : O(Target)
// Special Case : Base case changes when nums[0] == 0

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum - target < 0)
            return 0;

        if ((totalSum - target) % 2)
            return 0;

        int req = (totalSum - target) / 2;

        int n = nums.size();

        vector<int> prev(req + 1, 0);

        if (nums[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;

        if (nums[0] != 0 && nums[0] <= req)
            prev[nums[0]] = 1;

        for (int idx = 1; idx < n; idx++) {

            vector<int> curr(req + 1, 0);

            for (int sum = 0; sum <= req; sum++) {

                int notTake = prev[sum];

                int take = 0;
                if (nums[idx] <= sum)
                    take = prev[sum - nums[idx]];

                curr[sum] = take + notTake;
            }

            prev = curr;
        }

        return prev[req];
    }
};