#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> quickSort(vector<int> nums) {
        quickSortHelper(nums, 0, nums.size() - 1);
        return nums;
    }
    void quickSortHelper(vector<int>& nums, int low, int high){
        if (low >= high) return;

        int pivotIndex = partition(nums, low, high);

        quickSortHelper(nums, low, pivotIndex - 1);
        quickSortHelper(nums, pivotIndex + 1, high);
    }
    int partition(vector<int>& nums, int low, int high){
        int pivotElement = nums[high];
        int i = low - 1;
        
        for(int j = low; j < high; j++){
            if (nums[j] < pivotElement) {
                i++;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[i + 1], nums[high]);
        return i + 1;
    }
};

int main(){
    Solution sol;
    vector<int> result = sol.quickSort({7,4,6,1,8});
    for(int num : result){
        cout << num << " ";
    }
    return 0;
}