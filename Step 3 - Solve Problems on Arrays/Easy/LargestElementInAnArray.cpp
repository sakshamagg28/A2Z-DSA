class Solution {
public:
    int largestElement(vector<int>& nums) {
        int maxValue = nums[0];
        for (int i = 1; i < nums.size() ; i++){
            if (nums[i] > maxValue) maxValue = nums[i];
        }
        return maxValue;
    }
};
