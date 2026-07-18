// ==========================================================
// Method 1: Memoization (Top-Down DP)
//
// Time: O(n * target)
// Space: O(n * target) + O(n) recursion stack
//
// Interview Standard: Good for learning
// ==========================================================

class Solution {
public:
    const int MOD = 1e9 + 7;

    int f(int idx, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(idx == 0){
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || target == arr[0]) return 1;
            return 0;
        }

        if(dp[idx][target] != -1) return dp[idx][target];

        int notTake = f(idx - 1, target, arr, dp);

        int take = 0;
        if(arr[idx] <= target)
            take = f(idx - 1, target - arr[idx], arr, dp);

        return dp[idx][target] = (take + notTake) % MOD;
    }

    int countPartitions(int n, int diff, vector<int>& arr) {

        int total = accumulate(arr.begin(), arr.end(), 0);

        if(total < diff) return 0;
        if((total - diff) & 1) return 0;

        int target = (total - diff) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n - 1, target, arr, dp);
    }
};



// ==========================================================
// Method 2: Tabulation (Bottom-Up DP)
//
// Time: O(n * target)
// Space: O(n * target)
//
// Interview Standard: Common
// ==========================================================

class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPartitions(int n, int diff, vector<int>& arr) {

        int total = accumulate(arr.begin(), arr.end(), 0);

        if(total < diff) return 0;
        if((total - diff) & 1) return 0;

        int target = (total - diff) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1));

        if(arr[0] == 0)
            dp[0][0] = 2;
        else{
            dp[0][0] = 1;
            if(arr[0] <= target)
                dp[0][arr[0]] = 1;
        }

        for(int i = 1; i < n; i++){

            for(int sum = 0; sum <= target; sum++){

                int notTake = dp[i-1][sum];

                int take = 0;
                if(arr[i] <= sum)
                    take = dp[i-1][sum-arr[i]];

                dp[i][sum] = (take + notTake) % MOD;
            }
        }

        return dp[n-1][target];
    }
};



// ==========================================================
// Method 3: Space Optimized DP (Two Arrays)
//
// Time: O(n * target)
// Space: O(target)
//
// Interview Standard: Most Expected
// ==========================================================

class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPartitions(int n, int diff, vector<int>& arr) {

        int total = accumulate(arr.begin(), arr.end(), 0);

        if(total < diff) return 0;
        if((total - diff) & 1) return 0;

        int target = (total - diff) / 2;

        vector<int> prev(target + 1);

        if(arr[0] == 0)
            prev[0] = 2;
        else{
            prev[0] = 1;
            if(arr[0] <= target)
                prev[arr[0]] = 1;
        }

        for(int i = 1; i < n; i++){

            vector<int> cur(target + 1);

            for(int sum = 0; sum <= target; sum++){

                int notTake = prev[sum];

                int take = 0;
                if(arr[i] <= sum)
                    take = prev[sum-arr[i]];

                cur[sum] = (take + notTake) % MOD;
            }

            prev = cur;
        }

        return prev[target];
    }
};



// ==========================================================
// Method 4: Space Optimized DP (Single Array)
//
// Time: O(n * target)
// Space: O(target)
//
// Interview Standard: Most Optimal
// ==========================================================

class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPartitions(int n, int diff, vector<int>& arr) {

        int total = accumulate(arr.begin(), arr.end(), 0);

        if(total < diff) return 0;
        if((total - diff) & 1) return 0;

        int target = (total - diff) / 2;

        vector<int> dp(target + 1);
        dp[0] = 1;

        for(int x : arr){

            if(x == 0){

                for(int sum = 0; sum <= target; sum++)
                    dp[sum] = (2LL * dp[sum]) % MOD;
            }
            else{

                for(int sum = target; sum >= x; sum--)
                    dp[sum] = (dp[sum] + dp[sum - x]) % MOD;
            }
        }

        return dp[target];
    }
};