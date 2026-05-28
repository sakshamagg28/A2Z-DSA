class Solution {
public:
    int solve(vector<int>& nums, int start, int end){
        int prev2 = 0;
        int prev1 = 0;
        int curr = prev1;

        for (int i = start; i <= end; i++){
            curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        return max (solve(nums, 0, n-2), solve(nums, 1, n-1));


    }
};