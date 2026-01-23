class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 0);
        int product = 1;
        int countZero = 0;
        int index = -1;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != 0){
                product *= nums[i];
            } else {
                index = i;
                countZero += 1;
                if (countZero >= 2) return answer;
            }
        }
        if (countZero == 1){
            answer[index] = product;
            return answer;
        }
        for (int i = 0; i < nums.size(); i++){
            answer[i] = product/nums[i];
        }
        return answer;
    }
};