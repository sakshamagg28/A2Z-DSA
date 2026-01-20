class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int low = 0, mid, high = nums.size()-1;
        int count = 0;

        while (low <= high){
            mid = (low + high)/2;
            count++;
            if (nums[mid] == x){
                return mid;
            }
            else if (nums[mid] < x){
                low = mid + 1;
            }
            else if (nums[mid] > x){
                high = mid - 1;
            }
        }
        return low;
    }
};