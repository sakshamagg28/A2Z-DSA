class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> copy = nums;
        for (int i = 0; i < nums.size(); i++){
            for (int j = nums.size()-i ; j < nums.size() ; j++){
                nums[j] = copy[j-(nums.size()-i)];
            }
            for (int j = 0 ; j < nums.size()-i ; j++){
                nums[j] = copy[(j+i) % nums.size()];
            }

            bool sorted = true;
            for (int k = 0; k < nums.size() - 1; k++){
                if (nums[k] > nums[k+1]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted == true) return true;
        }
        return false;
    }
};