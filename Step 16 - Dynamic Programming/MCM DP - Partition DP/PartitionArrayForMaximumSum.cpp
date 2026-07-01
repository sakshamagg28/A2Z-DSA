// Method 1 : Memoization
// State : dp[i] = Maximum sum obtainable starting from index i
// Time : O(N*K)
// Space : O(N)

class Solution {
public:
    int f(int i, vector<int>& arr, int k, vector<int>& dp){
        if (i == arr.size()) return 0;

        if (dp[i] != -1) return dp[i];

        int maxi = 0;
        int ans = 0;

        for (int j = i; j < min((int)arr.size(), i + k); j++){
            maxi = max(maxi, arr[j]);

            int len = j - i + 1;

            ans = max(ans, len * maxi + f(j+1, arr, k, dp));
        }

        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n, -1);

        return f(0, arr, k, dp);
    }
};


// Method 2 : Tabulation
// State : dp[i] = Maximum sum obtainable starting from index i
// Time : O(N*K)
// Space : O(N)

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n+1, 0);

        for (int i = n-1; i >= 0; i--){
            int maxi = 0;
            int ans = 0;

            for (int j = i; j < min((int)arr.size(), i + k); j++){
                maxi = max(maxi, arr[j]);

                int len = j - i + 1;

                ans = max(ans, len * maxi + dp[j+1]);
            }

            dp[i] = ans;
        }

        return dp[0];
    }
};