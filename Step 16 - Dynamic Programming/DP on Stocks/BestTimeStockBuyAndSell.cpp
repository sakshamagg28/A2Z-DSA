// Method 1 : Brute Force
// Time : O(N²)
// Space : O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int ans = 0;

        for (int buy = 0; buy < n; buy++) {
            for (int sell = buy + 1; sell < n; sell++) {
                ans = max(ans, prices[sell] - prices[buy]);
            }
        }

        return ans;
    }
};


// Method 2 : Prefix Minimum (Optimal)
// Time : O(N)
// Space : O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int mini = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - mini);
            mini = min(mini, prices[i]);
        }

        return profit;
    }
};


// Method 3 : DP State Machine
// State : hold, notHold
// Time : O(N)
// Space : O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int hold = -prices[0];
        int notHold = 0;

        for (int i = 1; i < prices.size(); i++) {
            notHold = max(notHold, hold + prices[i]);
            hold = max(hold, -prices[i]);
        }

        return notHold;
    }
};