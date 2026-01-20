class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        vector<int> ans;
        int low = 0, mid, high = nums.size()-1;
        
        while (low <= high){
            mid = (low + high)/2;

            if (nums[mid] == x){
                return {mid, mid};
            }
            else if (nums[mid] < x){
                low = mid + 1;
            }
            else if (   nums[mid] > x){
                high = mid - 1;
            }
        }
        int floor = (high >= 0 ? high : -1);
        int ceil = (low < nums.size() ? low : -1);
        return {floor, ceil};
    }
};