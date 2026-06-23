// Method 1 : Recursion
// State : f(i,j)
// Time : O(2^(N+M))
// Space : O(N+M)

class Solution {
public:
    int f(int i, int j, string& str1, string& str2) {
        if (i < 0 || j < 0) return 0;

        if (str1[i] == str2[j])
            return 1 + f(i - 1, j - 1, str1, str2);

        return max(
            f(i - 1, j, str1, str2),
            f(i, j - 1, str1, str2)
        );
    }

    int longestCommonSubsequence(string str1, string str2) {
        return f(str1.size() - 1, str2.size() - 1, str1, str2);
    }
};


// Method 2 : Memoization
// State : dp[i][j]
// Time : O(N*M)
// Space : O(N*M)

class Solution {
public:
    int f(int i, int j, string& str1, string& str2,
          vector<vector<int>>& dp) {

        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (str1[i] == str2[j])
            return dp[i][j] =
                1 + f(i - 1, j - 1, str1, str2, dp);

        return dp[i][j] = max(
            f(i - 1, j, str1, str2, dp),
            f(i, j - 1, str1, str2, dp)
        );
    }

    int longestCommonSubsequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(
            n,
            vector<int>(m, -1)
        );

        return f(n - 1, m - 1, str1, str2, dp);
    }
};


// Method 3 : Tabulation
// State : dp[i][j]
// Time : O(N*M)
// Space : O(N*M)

class Solution {
public:
    int longestCommonSubsequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(m + 1, 0)
        );

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(
                        dp[i - 1][j],
                        dp[i][j - 1]
                    );
            }
        }

        return dp[n][m];
    }
};


// Method 4 : Space Optimized
// State : prev[j]
// Time : O(N*M)
// Space : O(M)

class Solution {
public:
    int longestCommonSubsequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<int> prev(m + 1, 0);

        for (int i = 1; i <= n; i++) {

            vector<int> curr(m + 1, 0);

            for (int j = 1; j <= m; j++) {

                if (str1[i - 1] == str2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(
                        prev[j],
                        curr[j - 1]
                    );
            }

            prev = curr;
        }

        return prev[m];
    }
};