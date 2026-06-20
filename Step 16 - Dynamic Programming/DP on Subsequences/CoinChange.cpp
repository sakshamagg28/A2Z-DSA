// Method 1 : Recursion (1D State)
// State : f(amount)
// Time : Exponential
// Space : O(Amount)

class Solution {
public:
    int f(int amount, vector<int>& coins) {
        if (amount == 0)
            return 0;

        if (amount < 0)
            return -1;

        int mini = INT_MAX;

        for (int coin : coins) {

            int take = f(amount - coin, coins);

            if (take != -1)
                mini = min(mini, 1 + take);
        }

        return mini == INT_MAX ? -1 : mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        return f(amount, coins);
    }
};



// Method 2 : Memoization (Recommended)
// State : dp[amount]
// Time : O(N*Amount)
// Space : O(Amount)

class Solution {
public:
    int f(int target, vector<int>& coins, vector<int>& dp){
        if (target == 0) return 0;
        if (target < 0) return -1;

        if (dp[target] != -2) return dp[target];

        int mini = INT_MAX;
        for (int coin : coins){
            int take = f(target - coin, coins, dp);

            if (take != -1){
                mini = min(mini, 1 + take);
            }
        }

        dp[target] = (mini == INT_MAX) ? -1 : mini;

        return dp[target];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, -2);

        return f(amount, coins, dp);
    }
};



// Method 3 : Tabulation (Recommended)
// State : dp[amount]
// Time : O(N*Amount)
// Space : O(Amount)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for (int amt = 1; amt <= amount; amt++) {
            for (int coin : coins) {
                if (coin <= amt)
                    dp[amt] = min(dp[amt], 1 + dp[amt - coin]);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};



// Method 4 : Unbounded Knapsack Memoization
// State : dp[idx][amount]
// Time : O(N*Amount)
// Space : O(N*Amount)

class Solution {
public:
    int INF = 1e9;

    int f(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {

        if (idx == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return INF;
        }

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int notTake = f(idx - 1, amount, coins, dp);

        int take = INF;
        if (coins[idx] <= amount)
            take = 1 + f(idx, amount - coins[idx], coins, dp);

        return dp[idx][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = f(n - 1, amount, coins, dp);

        return ans >= INF ? -1 : ans;
    }
};