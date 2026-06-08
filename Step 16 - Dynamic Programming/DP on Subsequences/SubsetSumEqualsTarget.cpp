class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int target){
        vector<int> dp(target+1, false);
        dp[0] = true;

        for (int num : arr){
            for (int j = target; j >= num; j--){
                dp[j] = dp[j] || dp[j-num];
            }
        }

        return dp[target];
    }
};  



// Tabulation
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));

        for(int i = 0; i < n; i++) dp[i][0] = true;
        dp[0][arr[0]] = true;

        for (int i = 1; i < n; i++){
            for (int j = 1; j <= target; j++){
                bool notTake = dp[i - 1][j];
                bool take = false;
                if (arr[i] <= j) take = dp[i-1][j - arr[i]];
                dp[i][j] = take | notTake;
            }
        }

        return dp[n-1][target];
    }
};