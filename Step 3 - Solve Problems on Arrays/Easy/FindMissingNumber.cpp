class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int minElement = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] < minElement) minElement = nums[i];
        }

        for (int i = 0; i <= nums.size() ; i++){
            if (find(nums.begin(), nums.end(), minElement + i) == nums.end()){
                return minElement + i;
            }
        }
        return -1;
    }
};