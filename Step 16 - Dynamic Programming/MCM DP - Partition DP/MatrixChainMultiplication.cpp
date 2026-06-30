// Method 1 : Recursion
// State : f(i,j) = Minimum cost to multiply matrices from i to j
// Time : Exponential
// Space : O(N)

class Solution {
public:
    int f(int i, int j, vector<int>& nums) {

        if (i == j)
            return 0;

        int mini = INT_MAX;

        for (int k = i; k < j; k++) {

            int cost =
                f(i, k, nums) +
                f(k + 1, j, nums) +
                nums[i - 1] * nums[k] * nums[j];

            mini = min(mini, cost);
        }

        return mini;
    }

    int matrixMultiplication(vector<int>& nums) {

        int n = nums.size();

        return f(1, n - 1, nums);
    }
};


// Method 2 : Memoization
// State : dp[i][j]
// Time : O(N³)
// Space : O(N²)

class Solution {
public:
    int f(int i, int j, vector<int>& nums,
          vector<vector<int>>& dp) {

        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;

        for (int k = i; k < j; k++) {

            int cost =
                f(i, k, nums, dp) +
                f(k + 1, j, nums, dp) +
                nums[i - 1] * nums[k] * nums[j];

            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int matrixMultiplication(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(1, n - 1, nums, dp);
    }
};


// Method 3 : Tabulation
// State : dp[i][j]
// Time : O(N³)
// Space : O(N²)

class Solution {
public:
    int matrixMultiplication(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(
            n,
            vector<int>(n, 0)
        );

        for (int i = n - 1; i >= 1; i--) {

            for (int j = i + 1; j < n; j++) {

                int mini = INT_MAX;

                for (int k = i; k < j; k++) {

                    int cost =
                        dp[i][k] +
                        dp[k + 1][j] +
                        nums[i - 1] * nums[k] * nums[j];

                    mini = min(mini, cost);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][n - 1];
    }
};