#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> bubbleSort(vector<int> nums) {
        bubbleSortHelper(nums, nums.size());
        return nums;
    }
    void bubbleSortHelper(vector<int>& nums, int n) {
        if (n == 1) return;

        for (int i = 0; i < n-1; i++){
            if (nums[i] > nums[i+1]){
                int temp = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = temp;
            }
        }
        bubbleSortHelper(nums, n-1);
    }
};

int main(){
    Solution sol;
    vector<int> result = sol.bubbleSort({7,4,6,1,8});
    for(int num : result){
        cout << num << " ";
    }
    return 0;
}
