// Method 1 : Recursion
// State : f(day,buy)
// Time : O(2^N)
// Space : O(N)

class Solution {
public:
    int f(int day, int buy, vector<int>& prices) {

        if (day == prices.size())
            return 0;

        if (buy) {
            return max(
                -prices[day] + f(day + 1, 0, prices),
                f(day + 1, 1, prices)
            );
        }

        return max(
            prices[day] + f(day + 1, 1, prices),
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

        if (day == prices.size())
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
            prices[day] + f(day + 1, 1, prices, dp),
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

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int day = n-1; day >= 0; day--){
            dp[day][1] = max(-prices[day] + dp[day + 1][0], dp[day + 1][1]);

            dp[day][0] = max(prices[day] + dp[day + 1][1], dp[day + 1][0]);
            
        }

        return dp[0][1];
    }
};


// Method 4 : Space Optimized
// State : ahead[buy]
// Time : O(N)
// Space : O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> ahead(2, 0);

        for (int day = n-1; day >= 0; day--){
            vector<int> curr(2, 0);

            curr[1] = max(-prices[day] + ahead[0], ahead[1]);

            curr[0] = max(prices[day] + ahead[1], ahead[0]);
            
            ahead = curr;
        }

        return ahead[1];
    }
};


// Method 5 : Greedy (Recommended)
// Time : O(N)
// Space : O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }

        return profit;
    }
};