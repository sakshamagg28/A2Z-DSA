class Solution {
public:
    bool isPossible(vector<int>&nums, int k, int maxSum){
        int splits = 1;
        int currSum = 0;
        for (int i = 0; i <nums.size(); i++){
            if (currSum + nums[i] <= maxSum){
                currSum += nums[i];
            }
            else {
                currSum = nums[i];
                splits++;
            }
        }
        return splits <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        for (int num : nums){
            sum += num;
        }

        int low = *max_element(nums.begin(), nums.end());
        int high = sum;

        while (low <= high){
            int mid = low + (high-low)/2;

            if (isPossible(nums, k, mid)){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};