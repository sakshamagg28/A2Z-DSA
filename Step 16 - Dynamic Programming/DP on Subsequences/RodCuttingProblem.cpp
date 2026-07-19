// Method 1 : Memoization
// State : dp[idx][len]
// Time : O(N²)
// Space : O(N²)

class Solution{
public:
    int f(int idx, int len, vector<int>& price,
          vector<vector<int>>& dp){

        if(idx == 0)
            return len * price[0];

        if(dp[idx][len] != -1)
            return dp[idx][len];

        int notTake = f(idx - 1, len, price, dp);

        int take = 0;
        int rodLength = idx + 1;

        if(rodLength <= len)
            take = price[idx] + f(idx, len - rodLength, price, dp);

        return dp[idx][len] = max(take, notTake);
    }

    int rodCutting(vector<int> price, int n) {

        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, -1)
        );

        return f(n - 1, n, price, dp);
    }
};


// Method 2 : Tabulation
// State : dp[idx][len]
// Time : O(N²)
// Space : O(N²)

class Solution{
public:
    int rodCutting(vector<int> price, int n) {

        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, 0)
        );

        for(int len = 0; len <= n; len++)
            dp[0][len] = len * price[0];

        for(int idx = 1; idx < n; idx++){

            int rodLength = idx + 1;

            for(int len = 0; len <= n; len++){

                int notTake = dp[idx - 1][len];

                int take = 0;
                if(rodLength <= len)
                    take = price[idx] + dp[idx][len - rodLength];

                dp[idx][len] = max(take, notTake);
            }
        }

        return dp[n - 1][n];
    }
};


// Method 3 : Space Optimization (2 Arrays)
// Time : O(N²)
// Space : O(N)

class Solution{
public:
    int rodCutting(vector<int> price, int n) {

        vector<int> prev(n + 1, 0);

        for(int len = 0; len <= n; len++)
            prev[len] = len * price[0];

        for(int idx = 1; idx < n; idx++){

            vector<int> curr(n + 1, 0);
            int rodLength = idx + 1;

            for(int len = 0; len <= n; len++){

                int notTake = prev[len];

                int take = 0;
                if(rodLength <= len)
                    take = price[idx] + curr[len - rodLength];

                curr[len] = max(take, notTake);
            }

            prev = curr;
        }

        return prev[n];
    }
};


// Method 4 : Space Optimization (1 Array)
// Time : O(N²)
// Space : O(N)
// Feature : Optimal solution

class Solution{
public:
    int rodCutting(vector<int> price, int n) {

        vector<int> dp(n + 1, 0);

        for(int len = 0; len <= n; len++)
            dp[len] = len * price[0];

        for(int idx = 1; idx < n; idx++){

            int rodLength = idx + 1;

            for(int len = 0; len <= n; len++){

                if(rodLength <= len)
                    dp[len] = max(
                        dp[len],
                        price[idx] + dp[len - rodLength]
                    );
            }
        }

        return dp[n];
    }
};