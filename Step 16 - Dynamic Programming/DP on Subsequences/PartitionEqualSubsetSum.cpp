// Method 1 : Recursion
// State : f(idx,target)
// Time : O(2^N)
// Space : O(N)

class Solution {
public:
    bool f(int idx, int target, vector<int>& nums) {
        if (target == 0)
            return true;

        if (idx == 0)
            return nums[0] == target;

        bool notTake = f(idx - 1, target, nums);

        bool take = false;
        if (nums[idx] <= target)
            take = f(idx - 1, target - nums[idx], nums);

        return take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2)
            return false;

        return f(nums.size() - 1, sum / 2, nums);
    }
};

// Method 2 : Memoization
// State : dp[idx][target]
// Time : O(N*Target)
// Space : O(N*Target)

class Solution {
public:
    bool f(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0)
            return true;

        if (idx == 0)
            return nums[0] == target;

        if (dp[idx][target] != -1)
            return dp[idx][target];

        bool notTake = f(idx - 1, target, nums, dp);

        bool take = false;
        if (nums[idx] <= target)
            take = f(idx - 1, target - nums[idx], nums, dp);

        return dp[idx][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2)
            return false;

        int target = sum / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n - 1, target, nums, dp);
    }
};

// Method 3 : Tabulation
// State : dp[idx][target]
// Time : O(N*Target)
// Space : O(N*Target)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2)
            return false;

        int target = sum / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        for (int idx = 1; idx < n; idx++) {
            for (int tar = 1; tar <= target; tar++) {

                bool notTake = dp[idx - 1][tar];

                bool take = false;
                if (nums[idx] <= tar)
                    take = dp[idx - 1][tar - nums[idx]];

                dp[idx][tar] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }
};

// Method 4 : Space Optimized (Two Arrays)
// State : prev[target]
// Time : O(N*Target)
// Space : O(Target)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2)
            return false;

        int target = sum / 2;
        int n = nums.size();

        vector<bool> prev(target + 1, false);

        prev[0] = true;

        if (nums[0] <= target)
            prev[nums[0]] = true;

        for (int idx = 1; idx < n; idx++) {

            vector<bool> curr(target + 1, false);

            curr[0] = true;

            for (int tar = 1; tar <= target; tar++) {

                bool notTake = prev[tar];

                bool take = false;
                if (nums[idx] <= tar)
                    take = prev[tar - nums[idx]];

                curr[tar] = take || notTake;
            }

            prev = curr;
        }

        return prev[target];
    }
};

// Method 5 : Space Optimized (Single Array)
// State : dp[target]
// Time : O(N*Target)
// Space : O(Target)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2)
            return false;

        int target = sum / 2;
        int n = nums.size();

        vector<bool> dp(target + 1, false);

        dp[0] = true;

        if (nums[0] <= target)
            dp[nums[0]] = true;

        for (int idx = 1; idx < n; idx++) {
            for (int tar = target; tar >= nums[idx]; tar--) {
                dp[tar] = dp[tar] || dp[tar - nums[idx]];
            }
        }

        return dp[target];
    }
};
