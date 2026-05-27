class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int prev1 = max(nums[0], nums[1]);
        int prev2 = nums[0];
        int curr;

        for (int i = 2; i < n; i++){
            curr = max (prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};