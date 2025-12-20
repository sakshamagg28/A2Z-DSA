class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive, negative;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] >= 0) positive.push_back(nums[i]);
            else negative.push_back(nums[i]);
        }
        
        int i = 0, j = 0;
        while (i < nums.size()){
            nums[i] = positive[j];
            nums[i+1] = negative[j];
            i += 2;
            j++;
        }
        return nums;
    }
};