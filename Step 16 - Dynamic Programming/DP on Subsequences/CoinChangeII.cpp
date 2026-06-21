// Method 1 : Recursion
// State : f(idx,amount)
// Time : Exponential
// Space : O(Amount)

class Solution {
public:
    int f(int idx, int amount, vector<int>& coins) {

        if (idx == 0)
            return (amount % coins[0] == 0);

        int notTake = f(idx - 1, amount, coins);

        int take = 0;
        if (coins[idx] <= amount)
            take = f(idx, amount - coins[idx], coins);

        return take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        return f(coins.size() - 1, amount, coins);
    }
};



// Method 2 : Memoization
// State : dp[idx][amount]
// Time : O(N*Amount)
// Space : O(N*Amount)

class Solution {
public:
    int f(int idx, int amount, vector<int>& coins,
          vector<vector<int>>& dp) {

        if (idx == 0)
            return (amount % coins[0] == 0);

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int notTake = f(idx - 1, amount, coins, dp);

        int take = 0;
        if (coins[idx] <= amount)
            take = f(idx, amount - coins[idx], coins, dp);

        return dp[idx][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(
            n,
            vector<int>(amount + 1, -1)
        );

        return f(n - 1, amount, coins, dp);
    }
};



// Method 3 : Tabulation
// State : dp[idx][amount]
// Time : O(N*Amount)
// Space : O(N*Amount)

class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<unsigned long long>> dp(
            n,
            vector<unsigned long long>(amount + 1, 0)
        );

        for (int amt = 0; amt <= amount; amt++) {
            if (amt % coins[0] == 0)
                dp[0][amt] = 1;
        }

        for (int idx = 1; idx < n; idx++) {
            for (int amt = 0; amt <= amount; amt++) {

                unsigned long long notTake = dp[idx - 1][amt];

                unsigned long long take = 0;
                if (coins[idx] <= amt)
                    take = dp[idx][amt - coins[idx]];

                dp[idx][amt] = take + notTake;
            }
        }

        return (int)dp[n - 1][amount];
    }
};



// Method 4 : Space Optimized
// State : prev[amount]
// Time : O(N*Amount)
// Space : O(Amount)

class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<unsigned long long> prev(amount + 1, 0);

        for (int amt = 0; amt <= amount; amt++) {
            if (amt % coins[0] == 0)
                prev[amt] = 1;
        }

        for (int idx = 1; idx < n; idx++) {

            vector<unsigned long long> curr(amount + 1, 0);

            for (int amt = 0; amt <= amount; amt++) {

                unsigned long long notTake = prev[amt];

                unsigned long long take = 0;
                if (coins[idx] <= amt)
                    take = curr[amt - coins[idx]];

                curr[amt] = take + notTake;
            }

            prev = curr;
        }

        return (int)prev[amount];
    }
};



// Method 5 : Single Array Space Optimized
// State : dp[amount]
// Time : O(N*Amount)
// Space : O(Amount)
// Most Optimal

class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<unsigned long long> dp(amount + 1, 0);

        dp[0] = 1;

        for (int coin : coins) {
            for (int amt = coin; amt <= amount; amt++) {
                dp[amt] += dp[amt - coin];
            }
        }

        return (int)dp[amount];
    }
};