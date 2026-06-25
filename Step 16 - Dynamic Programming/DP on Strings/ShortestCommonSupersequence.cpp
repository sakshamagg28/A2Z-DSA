// Method 1 : Recursion
// State : f(i,j)
// Time : Exponential
// Space : O(N+M)

class Solution {
public:
    string f(int i, int j, string& str1, string& str2) {
        if (i < 0) return str2.substr(0, j + 1);
        if (j < 0) return str1.substr(0, i + 1);

        if (str1[i] == str2[j])
            return f(i - 1, j - 1, str1, str2) + str1[i];

        string take1 = f(i - 1, j, str1, str2) + str1[i];
        string take2 = f(i, j - 1, str1, str2) + str2[j];

        return (take1.size() < take2.size()) ? take1 : take2;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        return f(str1.size() - 1, str2.size() - 1, str1, str2);
    }
};


// Method 2 : Memoization
// State : dp[i][j]
// Time : O(N*M*(N+M))
// Space : O(N*M*(N+M))
// Stores strings in DP

class Solution {
public:
    string f(int i, int j, string& str1, string& str2,
             vector<vector<string>>& dp) {

        if (i < 0) return str2.substr(0, j + 1);
        if (j < 0) return str1.substr(0, i + 1);

        if (dp[i][j] != "#")
            return dp[i][j];

        if (str1[i] == str2[j])
            return dp[i][j] =
                f(i - 1, j - 1, str1, str2, dp) + str1[i];

        string take1 = f(i - 1, j, str1, str2, dp) + str1[i];
        string take2 = f(i, j - 1, str1, str2, dp) + str2[j];

        return dp[i][j] =
            (take1.size() < take2.size()) ? take1 : take2;
    }

    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size(), m = str2.size();

        vector<vector<string>> dp(
            n,
            vector<string>(m, "#")
        );

        return f(n - 1, m - 1, str1, str2, dp);
    }
};


// Method 3 : LCS Tabulation + Backtracking (Recommended)
// Time : O(N*M)
// Space : O(N*M)

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        string ans = "";

        int i = n;
        int j = m;
        
        while (i > 0 && j > 0){
            if (str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }
            else if (dp[i-1][j] > dp[i][j-1]){
                ans += str1[i-1];
                i--;
            }
            else {
                ans += str2[j-1];
                j--;
            }
        }

        while (i > 0){
            ans += str1[i-1];
            i--;
        }

        while (j > 0){
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};