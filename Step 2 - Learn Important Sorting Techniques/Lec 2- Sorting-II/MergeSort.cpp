class Solution {
public:
    vector<int> mergeSort(vector<int>& nums) {
        mergeSortHelper(nums, 0, nums.size());
    }
    vector<int> mergeSortHelper(vector<int>& nums, int low, int high) {
        if (low >= high) return nums;

        int mid = (low + high)/2 ;

        mergeSortHelper(nums, low, mid);
        mergeSortHelper(nums, mid+1, high);

        merge(nums, low, mid, high);
    }
    vector<int> merge(vector<int>& nums, int low, int mid, int high){
        vector<int> result;

        for (int i = low; i < mid; i++){
    
            if (nums[mid + 1] > nums[i]){
                result.pushback(nums[])
                for (int j = mid + 1; j <= high; j++){
                    
                }
                result.pushback(nums[j]);
            }
            else {
                result.pushback(nums[i]);
            }
            
        }
    }
};
