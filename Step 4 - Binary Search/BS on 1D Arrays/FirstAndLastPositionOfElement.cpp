class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result = {left_bound(nums, target), right_bound(nums,target)};
        return result;
    }

private:
    int left_bound(vector<int> nums, int target){
        int low = 0, mid, high = nums.size()-1;

        while(low < high){
            mid = (low + high)/2;

            if (nums[mid] >= target){
                high = mid;
            }
            else if (nums[mid] < target){
                low = mid + 1;
            }
        }
        return (low < nums.size() && nums[low] == target) ? low : -1;
    }

    int right_bound(vector<int> nums, int target){
        int low = 0, mid, high = nums.size()-1;

        while(low <= high){
            mid = (low + high)/2;

            if (nums[mid] > target){
                high = mid - 1;
            }
            else if (nums[mid] <= target){
                low = mid + 1;
            }
        }
        return (high >= 0 && nums[high] == target) ? high : -1;
    }
};