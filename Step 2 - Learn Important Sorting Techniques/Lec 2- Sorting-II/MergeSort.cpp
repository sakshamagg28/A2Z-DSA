#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> mergeSort(vector<int> nums) {
        mergeSortHelper(nums, 0, nums.size()-1);
        return nums;
    }
    void mergeSortHelper(vector<int>& nums, int low, int high){
        if (low >= high) return;

        int mid = (low + high) / 2;

        mergeSortHelper(nums, low, mid);
        mergeSortHelper(nums, mid + 1, high);

        merge(nums, low, mid, high);
    }
    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;
        int left = low, right = mid + 1;
        
        while (left <= mid && right <= high){
            if (nums[left] > nums[right]){
                temp.push_back(nums[right++]);
            } else {
                temp.push_back(nums[left++]);
            }
        }
        while (left <= mid){
            temp.push_back(nums[left++]);
        }
        while (right <= high){
            temp.push_back(nums[right++]);
        }
        for (int i = low; i <= high; i++){
            nums[i] = temp[i - low];
        }
    }
};

int main(){
    Solution sol;
    vector<int> result = sol.mergeSort({7,4,6,1,8});
    for(int num : result){
        cout << num << " ";
    }
    return 0;
}
