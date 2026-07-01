// Method 1 : Memoization
// State : dp[i] = Minimum partitions needed starting from index i
// Time : O(N³)
// Space : O(N)

class Solution {
public:
    bool isPalindrome(int i, int j, string& s){
        while(i < j){
            if (s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }

    int f(int i, string& s, vector<int>& dp){
        if (i == s.size()){
            return 0;
        }

        if (dp[i] != -1) return dp[i];

        int mini = INT_MAX;

        for (int j = i; j < s.size(); j++){
            if (isPalindrome(i, j, s)){
                mini = min(mini, 1 + f(j+1, s, dp));
            }
        }

        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.size();

        vector<int> dp(n, -1);

        return f(0, s, dp) - 1;
    }
};


// Method 2 : Tabulation
// State : dp[i] = Minimum partitions needed starting from index i
// Time : O(N³)
// Space : O(N)

class Solution {
public:
    bool isPalindrome(int i, int j, string& s){
        while(i < j){
            if (s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();

        vector<int> dp(n+1, 0);

        for (int i = n-1; i >= 0; i--){
            int mini = INT_MAX;

            for (int j = i; j < n; j++){
                if (isPalindrome(i, j, s)){
                    mini = min(mini, 1 + dp[j+1]);
                }
            }

            dp[i] = mini;
        }

        return dp[0] - 1;
    }
};


// Method 3 : Optimized Palindrome DP + Tabulation
// State :
// pal[i][j] = Whether s[i...j] is palindrome
// dp[i] = Minimum partitions needed starting from i
// Time : O(N²)
// Space : O(N²)
// Feature : Optimal solution

class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int mini = INT_MAX;

            for (int j = i; j < n; j++) {
                if (pal[i][j]) {
                    mini = min(mini, 1 + dp[j + 1]);
                }
            }

            dp[i] = mini;
        }

        return dp[0] - 1;
    }
};