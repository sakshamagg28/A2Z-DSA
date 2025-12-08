#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> insertionSort(vector<int> nums) {
        insertionSortHelper(nums, 0);
        return nums;
    }
    void insertionSortHelper(vector<int>& nums, int i) {
        if (i == nums.size()) return;

        for (int j = i; j > 0; j--){
            if (nums[j-1] > nums[j]){
                int temp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = temp;
            }
        }
        insertionSortHelper(nums, i+1);
    }
};

int main(){
    Solution sol;
    vector<int> result = sol.insertionSort({7,4,6,1,8});
    for(int num : result){
        cout << num << " ";
    }
    return 0;
}