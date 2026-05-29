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