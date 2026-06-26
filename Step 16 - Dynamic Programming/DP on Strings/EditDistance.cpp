// Method 1 : Recursion
// State : f(i,j)
// Time : Exponential
// Space : O(N+M)

class Solution {
public:
    int f(int i, int j, string& word1, string& word2) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;

        if (word1[i] == word2[j])
            return f(i - 1, j - 1, word1, word2);

        return 1 + min({
            f(i - 1, j, word1, word2),     // Delete
            f(i, j - 1, word1, word2),     // Insert
            f(i - 1, j - 1, word1, word2)  // Replace
        });
    }

    int minDistance(string word1, string word2) {
        return f(word1.size() - 1, word2.size() - 1, word1, word2);
    }
};


// Method 2 : Memoization
// State : dp[i][j]
// Time : O(N*M)
// Space : O(N*M)

class Solution {
public:
    int f(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]){
            return dp[i][j] = f(i-1, j-1, word1, word2, dp);
        }

        return dp[i][j] = 1 + min({
            f(i-1, j, word1, word2, dp), 
            f(i, j-1, word1, word2, dp), 
            f(i-1, j-1, word1, word2, dp)
        });
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n-1, m-1, word1, word2, dp);
    }
};


// Method 3 : Tabulation
// State : dp[i][j]
// Time : O(N*M)
// Space : O(N*M)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int i = 0; i <= n; i++){
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++){
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
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
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> prev(m+1, 0);

        for (int j = 0; j <= m; j++){
            prev[j] = j;
        }

        for (int i = 1; i <= n; i++){
            vector<int> curr(m+1, 0);
            curr[0] = i;

            for (int j = 1; j <= m; j++){
                if (word1[i-1] == word2[j-1]){
                    curr[j] = prev[j-1];
                }
                else {
                    curr[j] = 1 + min({prev[j], curr[j-1], prev[j-1]});
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};