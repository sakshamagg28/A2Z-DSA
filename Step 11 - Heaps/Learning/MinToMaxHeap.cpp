class Solution {
public:
    vector<int> minToMaxHeap(vector<int> nums) {
        for (int i = nums.size()/2-1; i >= 0; i--){
            maxHeapify(nums, i);
        }
        return nums;
    }

    void maxHeapify(vector<int>& nums, int index){
        int li = 2*index +1;
        int ri = 2*index +2;

        int larger = index;

        if (li < nums.size() && nums[larger] < nums[li]){
            larger = li;
        }
        if (ri < nums.size() && nums[larger] < nums[ri]){
            larger = ri;
        }
        if (larger != index){
            swap (nums[larger], nums[index]);
            maxHeapify(nums, larger);
        }
    }
};