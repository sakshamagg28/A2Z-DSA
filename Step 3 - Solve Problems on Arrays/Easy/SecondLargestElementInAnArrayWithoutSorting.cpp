#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int secondLargestElement(vector<int> nums) {
        //your code goes here
        int maxValue = nums[0];
        for (int i = 0; i < (int)nums.size(); i++){
            if (nums[i] > maxValue) maxValue = nums[i];
        }
        
        nums.erase(remove(nums.begin(), nums.end(), maxValue), nums.end());

        if (nums.size() == 0) return -1;

        int secondLargest = nums[0];
        for (int i = 0; i < (int)nums.size(); i++){
            if (nums[i] > secondLargest) secondLargest = nums[i];
        }
        return secondLargest;
    }
};

int main(){
    Solution sol;
    int result = sol.secondLargestElement({8,2,6,7,4,8});
    cout << result;
    return 0;
}