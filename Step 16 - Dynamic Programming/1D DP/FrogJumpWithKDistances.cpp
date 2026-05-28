class Solution {
public:

    int frogJump(vector<int>& heights, int k) {

        int n = heights.size();

        vector<int> dp(n, INT_MAX);

        dp[0] = 0;

        for (int i = 1; i < n; i++) {

            for (int j = 1; j <= k; j++) {

                if (i - j >= 0) {

                    int jumpCost =
                        dp[i - j] +
                        abs(heights[i] - heights[i - j]);

                    dp[i] = min(dp[i], jumpCost);
                }
            }
        }

        return dp[n - 1];
    }
};