class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            int sum = 0;
            for (int j = i; j < nums.size(); j++){
                sum += nums[j];

                if (sum > maxSum) maxSum = sum;
            }
        }
        return maxSum;
    }
};