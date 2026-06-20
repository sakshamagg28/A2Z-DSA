//==============================================================//
// Method 1 : Recursion
// State : f(idx,target)
// Time Complexity : O(2^N)
// Space Complexity : O(N)
//==============================================================//

class Solution {
public:
    bool f(int idx, int target, vector<int>& arr) {
        if (target == 0)
            return true;

        if (idx == 0)
            return arr[0] == target;

        bool notTake = f(idx - 1, target, arr);

        bool take = false;
        if (arr[idx] <= target)
            take = f(idx - 1, target - arr[idx], arr);

        return take || notTake;
    }

    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        return f(n - 1, target, arr);
    }
};

//==============================================================//
// Method 2 : Memoization
// State : dp[idx][target]
// Time Complexity : O(N*Target)
// Space Complexity : O(N*Target)
//==============================================================//

class Solution {
public:
    bool f(int idx, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0)
            return true;

        if (idx == 0)
            return arr[0] == target;

        if (dp[idx][target] != -1)
            return dp[idx][target];

        bool notTake = f(idx - 1, target, arr, dp);

        bool take = false;
        if (arr[idx] <= target)
            take = f(idx - 1, target - arr[idx], arr, dp);

        return dp[idx][target] = take || notTake;
    }

    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n - 1, target, arr, dp);
    }
};

//==============================================================//
// Method 3 : Tabulation
// State : dp[idx][target]
// Time Complexity : O(N*Target)
// Space Complexity : O(N*Target)
//==============================================================//

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (arr[0] <= target)
            dp[0][arr[0]] = true;

        for (int idx = 1; idx < n; idx++) {
            for (int sum = 1; sum <= target; sum++) {

                bool notTake = dp[idx - 1][sum];

                bool take = false;
                if (arr[idx] <= sum)
                    take = dp[idx - 1][sum - arr[idx]];

                dp[idx][sum] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }
};

//==============================================================//
// Method 4 : Space Optimized
// State : prev[target]
// Time Complexity : O(N*Target)
// Space Complexity : O(Target)
//==============================================================//

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();

        vector<bool> prev(target + 1, false);

        prev[0] = true;

        if (arr[0] <= target)
            prev[arr[0]] = true;

        for (int idx = 1; idx < n; idx++) {

            vector<bool> curr(target + 1, false);

            curr[0] = true;

            for (int sum = 1; sum <= target; sum++) {

                bool notTake = prev[sum];

                bool take = false;
                if (arr[idx] <= sum)
                    take = prev[sum - arr[idx]];

                curr[sum] = take || notTake;
            }

            prev = curr;
        }

        return prev[target];
    }
};

//==============================================================//
// Method 5 : Single Array Space Optimization
// State : dp[target]
// Time Complexity : O(N*Target)
// Space Complexity : O(Target)
//==============================================================//

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();

        vector<bool> dp(target + 1, false);

        dp[0] = true;

        if (arr[0] <= target)
            dp[arr[0]] = true;

        for (int idx = 1; idx < n; idx++) {
            for (int sum = target; sum >= arr[idx]; sum--) {
                dp[sum] = dp[sum] || dp[sum - arr[idx]];
            }
        }

        return dp[target];
    }
};
