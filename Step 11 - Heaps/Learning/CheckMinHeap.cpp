class Solution {
public:
    bool isHeap(vector<int>& nums) {
        for (int i = 1 ; i < nums.size(); i++){
            if (nums[i] < nums[(i-1)/2]) {
                return false;
            }
        }
        return true;
    }
};