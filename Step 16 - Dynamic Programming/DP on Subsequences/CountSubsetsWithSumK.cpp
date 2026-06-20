// Method 1 : Recursion
// State : f(idx,target)
// Time : O(2^N)
// Space : O(N)

class Solution {
public:
    const int MOD = 1e9 + 7;

    int f(int idx, int target, vector<int>& arr) {
        if (target == 0)
            return 1;

        if (idx == 0)
            return arr[0] == target;

        int notTake = f(idx - 1, target, arr);

        int take = 0;
        if (arr[idx] <= target)
            take = f(idx - 1, target - arr[idx], arr);

        return (take + notTake) % MOD;
    }

    int perfectSum(vector<int>& arr, int K) {
        return f(arr.size() - 1, K, arr);
    }
};



// Method 2 : Memoization
// State : dp[idx][target]
// Time : O(N*K)
// Space : O(N*K)

class Solution {
public:
    const int MOD = 1e9 + 7;

    int f(int idx, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0)
            return 1;

        if (idx == 0)
            return arr[0] == target;

        if (dp[idx][target] != -1)
            return dp[idx][target];

        int notTake = f(idx - 1, target, arr, dp);

        int take = 0;
        if (arr[idx] <= target)
            take = f(idx - 1, target - arr[idx], arr, dp);

        return dp[idx][target] = (take + notTake) % MOD;
    }

    int perfectSum(vector<int>& arr, int K) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(K + 1, -1));

        return f(n - 1, K, arr, dp);
    }
};



// Method 3 : Tabulation
// State : dp[idx][target]
// Time : O(N*K)
// Space : O(N*K)

class Solution {
public:
    int perfectSum(vector<int>& arr, int K) {
        const int MOD = 1e9 + 7;

        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(K + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        if (arr[0] <= K)
            dp[0][arr[0]] = 1;

        for (int idx = 1; idx < n; idx++) {
            for (int target = 1; target <= K; target++) {

                int notTake = dp[idx - 1][target];

                int take = 0;
                if (arr[idx] <= target)
                    take = dp[idx - 1][target - arr[idx]];

                dp[idx][target] = (take + notTake) % MOD;
            }
        }

        return dp[n - 1][K];
    }
};



// Method 4 : Space Optimized
// State : prev[target]
// Time : O(N*K)
// Space : O(K)

class Solution {
public:
    int perfectSum(vector<int>& arr, int K) {
        const int MOD = 1e9 + 7;

        int n = arr.size();

        vector<int> prev(K + 1, 0);

        prev[0] = 1;

        if (arr[0] <= K)
            prev[arr[0]] = 1;

        for (int idx = 1; idx < n; idx++) {

            vector<int> curr(K + 1, 0);

            curr[0] = 1;

            for (int target = 1; target <= K; target++) {

                int notTake = prev[target];

                int take = 0;
                if (arr[idx] <= target)
                    take = prev[target - arr[idx]];

                curr[target] = (take + notTake) % MOD;
            }

            prev = curr;
        }

        return prev[K];
    }
};