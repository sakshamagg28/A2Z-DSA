// Method 1 : Recursion
// State : f(i,j,count)
// Time : Exponential
// Space : O(N+M)

class Solution {
public:
    int f(int i, int j, int count,
          string& str1, string& str2) {

        if (i < 0 || j < 0)
            return count;

        int take = count;

        if (str1[i] == str2[j])
            take = f(i - 1, j - 1, count + 1, str1, str2);

        int notTake1 = f(i - 1, j, 0, str1, str2);
        int notTake2 = f(i, j - 1, 0, str1, str2);

        return max({take, notTake1, notTake2});
    }

    int longestCommonSubstr(string str1, string str2) {
        return f(
            str1.size() - 1,
            str2.size() - 1,
            0,
            str1,
            str2
        );
    }
};


// Method 2 : Tabulation
// State : dp[i][j]
// Time : O(N*M)
// Space : O(N*M)

class Solution {
public:
    int longestCommonSubstr(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(m + 1, 0)
        );

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }

        return ans;
    }
};


// Method 3 : Space Optimized
// State : prev[j]
// Time : O(N*M)
// Space : O(M)

class Solution {
public:
    int longestCommonSubstr(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<int> prev(m + 1, 0);

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            vector<int> curr(m + 1, 0);

            for (int j = 1; j <= m; j++) {

                if (str1[i - 1] == str2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                    ans = max(ans, curr[j]);
                }
                else {
                    curr[j] = 0;
                }
            }

            prev = curr;
        }

        return ans;
    }
};