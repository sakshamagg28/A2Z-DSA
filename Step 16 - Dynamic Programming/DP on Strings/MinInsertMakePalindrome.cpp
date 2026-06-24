// Method 1 : Recursion
// State : f(i,j)
// Time : Exponential
// Space : O(N)

class Solution {
public:
    int f(int i, int j, string& s) {

        if (i >= j)
            return 0;

        if (s[i] == s[j])
            return f(i + 1, j - 1, s);

        return 1 + min(
            f(i + 1, j, s),
            f(i, j - 1, s)
        );
    }

    int minInsertions(string s) {
        return f(0, s.size() - 1, s);
    }
};


// Method 2 : Memoization
// State : dp[i][j]
// Time : O(N²)
// Space : O(N²)

class Solution {
public:
    int f(int i, int j, string& s,
          vector<vector<int>>& dp) {

        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = f(i + 1, j - 1, s, dp);

        return dp[i][j] = 1 + min(
            f(i + 1, j, s, dp),
            f(i, j - 1, s, dp)
        );
    }

    int minInsertions(string s) {

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(0, n - 1, s, dp);
    }
};


// Method 3 : Tabulation
// State : dp[i][j]
// Time : O(N²)
// Space : O(N²)

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--){
            for (int j = i + 1; j < n; j++){
                if (s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};


// Method 4 : LPS Transformation + Tabulation
// Observation : Answer = N - LPS
// Time : O(N²)
// Space : O(N²)

class Solution {
public:
    int minInsertions(string s) {

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

        int lps = dp[n][n];

        return n - lps;
    }
};


// Method 5 : LPS Transformation + Space Optimized
// Observation : Answer = N - LPS
// Time : O(N²)
// Space : O(N)

class Solution {
public:
    int minInsertions(string s) {

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
                    curr[j] = max(prev[j], curr[j - 1]);
            }

            prev = curr;
        }

        int lps = prev[n];

        return n - lps;
    }
};