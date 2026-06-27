// Method 1 : Recursion
// State : f(day,buy)
// Time : Exponential
// Space : O(N)

class Solution {
public:
    int f(int day, int buy, vector<int>& prices) {

        if (day >= prices.size())
            return 0;

        if (buy) {
            return max(
                -prices[day] + f(day + 1, 0, prices),
                f(day + 1, 1, prices)
            );
        }

        return max(
            prices[day] + f(day + 2, 1, prices),
            f(day + 1, 0, prices)
        );
    }

    int maxProfit(vector<int>& prices) {
        return f(0, 1, prices);
    }
};


// Method 2 : Memoization
// State : dp[day][buy]
// Time : O(N)
// Space : O(N)

class Solution {
public:
    int f(int day, int buy, vector<int>& prices,
          vector<vector<int>>& dp) {

        if (day >= prices.size())
            return 0;

        if (dp[day][buy] != -1)
            return dp[day][buy];

        if (buy) {
            return dp[day][buy] = max(
                -prices[day] + f(day + 1, 0, prices, dp),
                f(day + 1, 1, prices, dp)
            );
        }

        return dp[day][buy] = max(
            prices[day] + f(day + 2, 1, prices, dp),
            f(day + 1, 0, prices, dp)
        );
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(
            n,
            vector<int>(2, -1)
        );

        return f(0, 1, prices, dp);
    }
};


// Method 3 : Tabulation
// State : dp[day][buy]
// Time : O(N)
// Space : O(N)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(
            n + 2,
            vector<int>(2, 0)
        );

        for (int day = n - 1; day >= 0; day--) {

            dp[day][1] = max(
                -prices[day] + dp[day + 1][0],
                dp[day + 1][1]
            );

            dp[day][0] = max(
                prices[day] + dp[day + 2][1],
                dp[day + 1][0]
            );
        }

        return dp[0][1];
    }
};


// Method 4 : Space Optimized
// State : ahead1[buy] = day+1
//         ahead2[buy] = day+2
// Time : O(N)
// Space : O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        vector<int> ahead1(2, 0);
        vector<int> ahead2(2, 0);

        for (int day = prices.size() - 1; day >= 0; day--) {

            vector<int> curr(2);

            curr[1] = max(
                -prices[day] + ahead1[0],
                ahead1[1]
            );

            curr[0] = max(
                prices[day] + ahead2[1],
                ahead1[0]
            );

            ahead2 = ahead1;
            ahead1 = curr;
        }

        return ahead1[1];
    }
};