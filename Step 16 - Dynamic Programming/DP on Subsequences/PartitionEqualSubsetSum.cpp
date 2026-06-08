class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if (sum % 2 != 0) return false;

        int target = sum/2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums){
            for (int j = target; j >= num; j--){
                dp[j] = dp[j] || dp[j-num];
            }
        }
        return dp[target];
    }
};



// Memoization
class Solution {
public:
    bool f(vector<int>& nums, vector<vector<int>>& dp, int target, int index){
        if (target == 0) return true;
        if (index == 0) return (nums[0] == target);

        if (dp[index][target] != -1) return dp[index][target];

        bool notTake = f(nums, dp, target, index - 1);
        bool take = false;
        if (target >= nums[index]) take = f(nums, dp, target - nums[index], index - 1);

        return dp[index][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;

        int target = sum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        return f(nums, dp, target, nums.size()-1);
    }
};