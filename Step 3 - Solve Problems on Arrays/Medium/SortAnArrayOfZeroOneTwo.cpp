class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        vector<int> count(4,0);
        for (auto itr = nums.begin(); itr != nums.end(); itr++){
            if (*itr == 0) count[0]++;
            else if (*itr == 1) count[1]++;
            else count[2]++;
        }
        for (int i = 0; i < count[0]; i++){
            nums[i] = 0;
        }
        for (int j = count[0]; j < count[0] + count[1]; j++){
            nums[j] = 1;
        }
        for (int k = count[0] + count[1]; k < count[0] + count[1] + count[2]; k++){
            nums[k] = 2;
        }
    }
};