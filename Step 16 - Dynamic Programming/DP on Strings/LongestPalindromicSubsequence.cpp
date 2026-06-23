// Method 1 : Recursion
// State : f(i,j)
// Time : O(2^N)
// Space : O(N)

class Solution {
public:
    int f(int i, int j, string& s) {

        if (i > j)
            return 0;

        if (i == j)
            return 1;

        if (s[i] == s[j])
            return 2 + f(i + 1, j - 1, s);

        return max(
            f(i + 1, j, s),
            f(i, j - 1, s)
        );
    }

    int longestPalindromeSubseq(string s) {
        return f(0, s.size() - 1, s);
    }
};



// Method 2 : Memoization
// State : dp[i][j]
// Time : O(N^2)
// Space : O(N^2)
// Memory Limit Exceeded for large test cases: O(N^2) + O(N) Recursion Stack Space

class Solution {
public:
    int f(int i, int j, string s, vector<vector<int>>& dp){
        if (i > j){
            return 0;
        }
        if (i == j){
            return 1;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]){
            return dp[i][j] = f(i+1, j-1, s, dp) + 2;
        }

        return dp[i][j] = max(f(i+1, j, s, dp), f(i, j-1, s, dp));
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(0, n-1, s, dp);
    }
};  



// Method 3 : Tabulation
// State : dp[i][j]
// Time : O(N^2)
// Space : O(N^2)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        
        for (int i = n-1; i >= 0; i--){
            for (int j = i+1; j < n; j++){
                if (s[i] == s[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else {
                    dp[i][j] = max (dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};



// Method 4 : LCS Transformation + Memoization
// State : dp[i][j]
// Time : O(N^2)
// Space : O(N^2)

class Solution {
public:
    int f(int i, int j,
          string& s, string& t,
          vector<vector<int>>& dp) {

        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] =
                1 + f(i - 1, j - 1, s, t, dp);

        return dp[i][j] = max(
            f(i - 1, j, s, t, dp),
            f(i, j - 1, s, t, dp)
        );
    }

    int longestPalindromeSubseq(string s) {

        string t = s;
        reverse(t.begin(), t.end());

        int n = s.size();

        vector<vector<int>> dp(
            n,
            vector<int>(n, -1)
        );

        return f(n - 1, n - 1, s, t, dp);
    }
};



// Method 5 : LCS Transformation + Tabulation
// State : dp[i][j]
// Time : O(N^2)
// Space : O(N^2)

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        string t = s;
        reverse(t.begin(), t.end());

        int n = s.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(n + 1, 0)
        );

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(
                        dp[i - 1][j],
                        dp[i][j - 1]
                    );
            }
        }

        return dp[n][n];
    }
};



// Method 6 : LCS Transformation + Space Optimized
// State : prev[j]
// Time : O(N^2)
// Space : O(N)

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        string t = s;
        reverse(t.begin(), t.end());

        int n = s.size();

        vector<int> prev(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            vector<int> curr(n + 1, 0);

            for (int j = 1; j <= n; j++) {

                if (s[i - 1] == t[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(
                        prev[j],
                        curr[j - 1]
                    );
            }

            prev = curr;
        }

        return prev[n];
    }
};