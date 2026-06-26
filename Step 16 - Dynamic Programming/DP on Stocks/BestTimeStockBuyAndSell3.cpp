// Method 1 : Recursion
// State : f(day,buy,cap)
// Time : Exponential
// Space : O(N)

class Solution {
public:
    int f(int day, int buy, int cap, vector<int>& prices) {

        if (day == prices.size() || cap == 0)
            return 0;

        if (buy) {
            return max(
                -prices[day] + f(day + 1, 0, cap, prices),
                f(day + 1, 1, cap, prices)
            );
        }

        return max(
            prices[day] + f(day + 1, 1, cap - 1, prices),
            f(day + 1, 0, cap, prices)
        );
    }

    int maxProfit(vector<int>& prices) {
        return f(0, 1, 2, prices);
    }
};


// Method 2 : Memoization
// State : dp[day][buy][cap]
// Time : O(N*2*3)
// Space : O(N*2*3)

class Solution {
public:
    int f(int day, int buy, int cap, vector<int>& prices,
          vector<vector<vector<int>>>& dp) {

        if (day == prices.size() || cap == 0)
            return 0;

        if (dp[day][buy][cap] != -1)
            return dp[day][buy][cap];

        if (buy) {
            return dp[day][buy][cap] = max(
                -prices[day] + f(day + 1, 0, cap, prices, dp),
                f(day + 1, 1, cap, prices, dp)
            );
        }

        return dp[day][buy][cap] = max(
            prices[day] + f(day + 1, 1, cap - 1, prices, dp),
            f(day + 1, 0, cap, prices, dp)
        );
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return f(0, 1, 2, prices, dp);
    }
};


// Method 3 : Tabulation
// State : dp[day][buy][cap]
// Time : O(N*2*3)
// Space : O(N*2*3)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int day = n-1; day >= 0; day--){
            for (int buy = 0; buy <= 1; buy++){
                for (int cap = 1; cap <= 2; cap++){
                    if (buy){
                        dp[day][buy][cap] = max(-prices[day] + dp[day+1][0][cap], dp[day+1][1][cap]);
                    }
                    else{
                        dp[day][buy][cap] = max(prices[day] + dp[day+1][1][cap-1], dp[day+1][0][cap]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};


// Method 4 : Space Optimized
// State : ahead[buy][cap]
// Time : O(N*2*3)
// Space : O(2*3)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> ahead(2, vector<int>(3, 0));

        for (int day = n-1; day >= 0; day--){
            vector<vector<int>> curr(2, vector<int>(3, 0));

            for (int buy = 0; buy <= 1; buy++){
                for (int cap = 1; cap <= 2; cap++){
                    if (buy){
                        curr[buy][cap] = max(-prices[day] + ahead[0][cap], ahead[1][cap]);
                    }
                    else{
                        curr[buy][cap] = max(prices[day] + ahead[1][cap-1], ahead[0][cap]);
                    }
                }
            }

            ahead = curr;
        }

        return ahead[1][2];
    }
};