#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> quickSort(vector<int> nums) {

    }
    void quickSortHelper(vector<int>& nums, int low, int high){
        if (low >= high) return;

        int pivotIndex = partition(nums, low, high);

        quickSortHelper(nums, low, pivotIndex - 1);
        quickSortHelper(nums, pivotIndex + 1, high);
    }
    int partition(vector<int>& nums, int low, int high){
        int pivotIndex 
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