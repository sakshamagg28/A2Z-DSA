//==============================================================//
// Method 1 : Recursion
// State : f(row,col1,col2)
// Time Complexity : O(9^R)
// Space Complexity : O(R)
//==============================================================//

class Solution {
public:
    int f(int row, int col1, int col2, vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();

        if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m)
            return -1e9;

        if (row == n - 1) {
            if (col1 == col2)
                return g[row][col1];
            return g[row][col1] + g[row][col2];
        }

        int maxi = -1e9;

        for (int dcol1 = -1; dcol1 <= 1; dcol1++) {
            for (int dcol2 = -1; dcol2 <= 1; dcol2++) {

                int value;

                if (col1 == col2)
                    value = g[row][col1];
                else
                    value = g[row][col1] + g[row][col2];

                value += f(row + 1, col1 + dcol1, col2 + dcol2, g);

                maxi = max(maxi, value);
            }
        }

        return maxi;
    }

    int maxChocolates(vector<vector<int>>& g) {
        return f(0, 0, g[0].size() - 1, g);
    }
};

//==============================================================//
// Method 2 : Memoization
// State : dp[row][col1][col2]
// Time Complexity : O(R*C*C*9)
// Space Complexity : O(R*C*C)
//==============================================================//

class Solution {
public:
    int f(int row, int col1, int col2, vector<vector<int>>& g,
          vector<vector<vector<int>>>& dp) {

        int n = g.size();
        int m = g[0].size();

        if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m)
            return -1e9;

        if (row == n - 1) {
            if (col1 == col2)
                return g[row][col1];
            return g[row][col1] + g[row][col2];
        }

        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        int maxi = -1e9;

        for (int dcol1 = -1; dcol1 <= 1; dcol1++) {
            for (int dcol2 = -1; dcol2 <= 1; dcol2++) {

                int value;

                if (col1 == col2)
                    value = g[row][col1];
                else
                    value = g[row][col1] + g[row][col2];

                value += f(row + 1, col1 + dcol1, col2 + dcol2, g, dp);

                maxi = max(maxi, value);
            }
        }

        return dp[row][col1][col2] = maxi;
    }

    int maxChocolates(vector<vector<int>>& g) {

        int n = g.size();
        int m = g[0].size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(m, vector<int>(m, -1))
        );

        return f(0, 0, m - 1, g, dp);
    }
};

//==============================================================//
// Method 3 : Tabulation
// State : dp[row][col1][col2]
// Time Complexity : O(R*C*C*9)
// Space Complexity : O(R*C*C)
//==============================================================//

class Solution {
public:
    int maxChocolates(vector<vector<int>>& g) {

        int n = g.size();
        int m = g[0].size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(m, vector<int>(m))
        );

        for (int col1 = 0; col1 < m; col1++) {
            for (int col2 = 0; col2 < m; col2++) {

                if (col1 == col2)
                    dp[n - 1][col1][col2] = g[n - 1][col1];
                else
                    dp[n - 1][col1][col2] = g[n - 1][col1] + g[n - 1][col2];
            }
        }

        for (int row = n - 2; row >= 0; row--) {
            for (int col1 = 0; col1 < m; col1++) {
                for (int col2 = 0; col2 < m; col2++) {

                    int maxi = -1e9;

                    for (int dcol1 = -1; dcol1 <= 1; dcol1++) {
                        for (int dcol2 = -1; dcol2 <= 1; dcol2++) {
                            
                            int value;

                            if (col1 == col2)
                                value = g[row][col1];
                            else
                                value = g[row][col1] + g[row][col2];

                            if (col1 + dcol1 >= 0 && col1 + dcol1 < m &&
                                col2 + dcol2 >= 0 && col2 + dcol2 < m)
                                value += dp[row + 1][col1 + dcol1][col2 + dcol2];
                            else
                                value = -1e9;

                            maxi = max(maxi, value);
                        }
                    }

                    dp[row][col1][col2] = maxi;
                }
            }
        }

        return dp[0][0][m - 1];
    }
};

//==============================================================//
// Method 4 : Space Optimized
// State : prev[col1][col2]
// Time Complexity : O(R*C*C*9)
// Space Complexity : O(C*C)
//==============================================================//

class Solution {
public:
    int maxChocolates(vector<vector<int>>& g) {

        int n = g.size();
        int m = g[0].size();

        vector<vector<int>> prev(m, vector<int>(m));

        for (int col1 = 0; col1 < m; col1++) {
            for (int col2 = 0; col2 < m; col2++) {

                if (col1 == col2)
                    prev[col1][col2] = g[n - 1][col1];
                else
                    prev[col1][col2] = g[n - 1][col1] + g[n - 1][col2];
            }
        }

        for (int row = n - 2; row >= 0; row--) {

            vector<vector<int>> curr(m, vector<int>(m));

            for (int col1 = 0; col1 < m; col1++) {

                for (int col2 = 0; col2 < m; col2++) {

                    int maxi = -1e9;

                    for (int dcol1 = -1; dcol1 <= 1; dcol1++) {

                        for (int dcol2 = -1; dcol2 <= 1; dcol2++) {

                            int value;

                            if (col1 == col2)
                                value = g[row][col1];
                            else
                                value = g[row][col1] + g[row][col2];

                            if (col1 + dcol1 >= 0 && col1 + dcol1 < m &&
                                col2 + dcol2 >= 0 && col2 + dcol2 < m)
                                value += prev[col1 + dcol1][col2 + dcol2];
                            else
                                value = -1e9;

                            maxi = max(maxi, value);
                        }
                    }

                    curr[col1][col2] = maxi;
                }
            }

            prev = curr;
        }

        return prev[0][m - 1];
    }
};
