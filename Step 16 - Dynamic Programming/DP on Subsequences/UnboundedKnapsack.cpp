// Method 1 : Memoization
// State : dp[idx][W]
// Time : O(N*W)
// Space : O(N*W)

class Solution{
public:
    int f(int idx, int W, vector<int>& wt, vector<int>& val,
          vector<vector<int>>& dp){

        if(idx == 0)
            return (W / wt[0]) * val[0];

        if(dp[idx][W] != -1)
            return dp[idx][W];

        int notTake = f(idx - 1, W, wt, val, dp);

        int take = 0;
        if(wt[idx] <= W)
            take = val[idx] + f(idx, W - wt[idx], wt, val, dp);

        return dp[idx][W] = max(take, notTake);
    }

    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W){

        vector<vector<int>> dp(
            n,
            vector<int>(W + 1, -1)
        );

        return f(n - 1, W, wt, val, dp);
    }
};


// Method 2 : Tabulation
// State : dp[idx][W]
// Time : O(N*W)
// Space : O(N*W)

class Solution{
public:
    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W){

        vector<vector<int>> dp(
            n,
            vector<int>(W + 1, 0)
        );

        for(int w = 0; w <= W; w++)
            dp[0][w] = (w / wt[0]) * val[0];

        for(int idx = 1; idx < n; idx++){

            for(int w = 0; w <= W; w++){

                int notTake = dp[idx - 1][w];

                int take = 0;
                if(wt[idx] <= w)
                    take = val[idx] + dp[idx][w - wt[idx]];

                dp[idx][w] = max(take, notTake);
            }
        }

        return dp[n - 1][W];
    }
};


// Method 3 : Space Optimization (2 Arrays)
// Time : O(N*W)
// Space : O(W)

class Solution{
public:
    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W){

        vector<int> prev(W + 1, 0);

        for(int w = 0; w <= W; w++)
            prev[w] = (w / wt[0]) * val[0];

        for(int idx = 1; idx < n; idx++){

            vector<int> curr(W + 1, 0);

            for(int w = 0; w <= W; w++){

                int notTake = prev[w];

                int take = 0;
                if(wt[idx] <= w)
                    take = val[idx] + curr[w - wt[idx]];

                curr[w] = max(take, notTake);
            }

            prev = curr;
        }

        return prev[W];
    }
};


// Method 4 : Space Optimization (1 Array)
// Time : O(N*W)
// Space : O(W)
// Feature : Optimal solution

class Solution{
public:
    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W){

        vector<int> dp(W + 1, 0);

        for(int w = 0; w <= W; w++)
            dp[w] = (w / wt[0]) * val[0];

        for(int idx = 1; idx < n; idx++){

            for(int w = 0; w <= W; w++){

                if(wt[idx] <= w)
                    dp[w] = max(
                        dp[w],
                        val[idx] + dp[w - wt[idx]]
                    );
            }
        }

        return dp[W];
    }
};