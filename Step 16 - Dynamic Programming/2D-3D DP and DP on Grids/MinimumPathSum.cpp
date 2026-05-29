class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        dp[0][0] = grid[0][0];

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (i == 0 && j == 0) continue;

                else if (i > 0 && j > 0){
                int down = dp[i][j-1] + grid[i][j];
                int right = dp[i-1][j] + grid[i][j];

                    dp[i][j] = min(down, right);
                }
                else if (i == 0){
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }
                else dp[i][j] = dp[i-1][j] + grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};


// Space Optimization O(n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n);

        dp[0] = grid[0][0];

        for (int j = 1; j < n; j++)
            dp[j] = dp[j - 1] + grid[0][j];

        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0];

            for (int j = 1; j < n; j++) {
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }

        return dp[n - 1];
    }
};



// Space Optimization O(n) - Alternative way to write the code
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n);

        dp[0] = grid[0][0];

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (i == 0 && j == 0) continue;

                else if (i > 0 && j > 0){
                int down = dp[j-1] + grid[i][j];
                int right = dp[j] + grid[i][j];

                    dp[j] = min(down, right);
                }
                else if (i == 0){
                    dp[j] = dp[j-1] + grid[i][j];
                }
                else dp[j] = dp[j] + grid[i][j];
            }
        }

        return dp[n-1];
    }
};