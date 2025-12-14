class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        vector<int> copy = nums;
        k = k % nums.size();
        for (int i = 0; i < nums.size()-k; i++){
            nums[i] = copy[(i+k) % nums.size()];
        }
        for (int i = nums.size()-k ; i < nums.size(); i++){
            nums[i] = copy[i - (nums.size()-k)];
        }
    }
};