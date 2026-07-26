class Solution {
public:
    vector<int> dp;

    bool solve(int mask, int remaining, int maxChoosableInteger) {
        if (dp[mask] != -1)
            return dp[mask];

        // Try every unused number
        for (int i = 1; i <= maxChoosableInteger; i++) {
            // If i is not used
            if (!(mask & (1 << (i - 1)))) {

                // Current player wins immediately
                if (i >= remaining)
                    return dp[mask] = true;

                // If opponent loses after choosing i,
                // current player wins
                if (!solve(mask | (1 << (i - 1)),
                           remaining - i,
                           maxChoosableInteger))
                    return dp[mask] = true;
            }
        }

        return dp[mask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0)
            return true;

        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;

        if (sum < desiredTotal)
            return false;

        dp.assign(1 << maxChoosableInteger, -1);

        return solve(0, desiredTotal, maxChoosableInteger);
    }
};