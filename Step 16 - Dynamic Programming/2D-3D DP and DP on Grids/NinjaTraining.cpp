class Solution {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(3, 0));

        dp[0][0] = matrix[0][0];
        dp[0][1] = matrix[0][1];
        dp[0][2] = matrix[0][2];

        for (int i = 1; i < n; i++){
            dp[i][0] = matrix[i][0] + max(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = matrix[i][1] + max(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = matrix[i][2] + max(dp[i-1][1], dp[i-1][0]);
        }

        return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
};