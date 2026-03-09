class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid, ans = -1;

        while (low <= high){
            mid = low + (high-low)/2;

            if (nums[mid] == target){
                ans = mid;
                break;
            }
            if (nums[low] <= nums[mid]){
                if (nums[mid] > target && target >= nums[low]){
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            else{
                if (nums[mid] < target && target <= nums[high]){
                    low = mid + 1;
                }
                else high = mid - 1;
            }
        }
        return ans;
    }
};