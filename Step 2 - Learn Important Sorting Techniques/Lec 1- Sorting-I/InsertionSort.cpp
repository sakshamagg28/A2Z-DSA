class Solution {
public:
    vector<int> insertionSort(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++){
            for (int j = i; j > 0; j--){
                if (nums[j-1] > nums[j]){
                    int temp = nums[j];
                    nums[j] = nums[j-1];
                    nums[j-1] = temp;
                }
            }
        }
        return nums;
    }
