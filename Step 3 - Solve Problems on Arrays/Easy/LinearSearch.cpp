class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {
        //your code goes here
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == target) {
                return i;
                break;
            }
        }
        return -1;
    }
};