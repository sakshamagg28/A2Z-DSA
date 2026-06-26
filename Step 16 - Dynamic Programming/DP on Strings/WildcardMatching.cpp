// Method 1 : Recursion
// State : f(i,j)
// Time : Exponential
// Space : O(N+M)

class Solution {
public:
    bool f(int i, int j, string& s, string& p) {

        if (i < 0 && j < 0) return true;
        if (j < 0) return false;

        if (i < 0) {
            for (int k = 0; k <= j; k++)
                if (p[k] != '*')
                    return false;
            return true;
        }

        if (s[i] == p[j] || p[j] == '?')
            return f(i - 1, j - 1, s, p);

        if (p[j] == '*')
            return f(i - 1, j, s, p) || f(i, j - 1, s, p);

        return false;
    }

    bool isMatch(string s, string p) {
        return f(s.size() - 1, p.size() - 1, s, p);
    }
};


// Method 2 : Memoization
// State : dp[i][j]
// Time : O(N*M)
// Space : O(N*M)

class Solution {
public:
    bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if (i < 0 && j < 0) return true;
        if (j < 0) return false;

        if (i < 0){
            for (int k = 0; k <= j; k++){
                if (p[k] != '*'){
                    return false;
                }
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = f(i-1, j-1, s, p, dp);
        }

        if (p[j] == '*'){
            return dp[i][j] = f(i-1, j, s, p, dp) + f(i, j-1, s, p, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n-1, m-1, s, p, dp);
    }
};


// Method 3 : Tabulation
// State : dp[i][j]
// Time : O(N*M)
// Space : O(N*M)

class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.size(), m = p.size();

        vector<vector<bool>> dp(
            n + 1,
            vector<bool>(m + 1, false)
        );

        dp[0][0] = true;

        for (int j = 1; j <= m; j++) {

            bool flag = true;

            for (int k = 1; k <= j; k++) {
                if (p[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }

            dp[0][j] = flag;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];

                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

                else
                    dp[i][j] = false;
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
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<bool> prev(m+1, false);

        prev[0] = true;

        for (int j = 0; j <= m; j++){
            bool flag = true;

            for (int k = 1; k <= j; k++){
                if (p[k-1] != '*'){
                    flag = false;
                    break;
                }
            }

            prev[j] = flag;
        }

        for (int i = 1; i <= n; i++){
            vector<bool> curr(m+1, false);

            for (int j = 1; j <= m; j++){

                if (s[i-1] == p[j-1] || p[j-1] == '?'){
                    curr[j] = prev[j-1];
                }

                else if (p[j-1] == '*'){
                    curr[j] = prev[j] || curr[j-1];
                }

                else {
                    curr[j] = false;
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};