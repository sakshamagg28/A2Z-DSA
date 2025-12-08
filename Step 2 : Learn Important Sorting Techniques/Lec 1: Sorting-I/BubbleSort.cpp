#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bubbleSort(vector<int> nums) {
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++){
                if (nums[j] > nums[j+1]) swap(nums[j], nums[j+1]);
            }
        }
        return nums;
    }
};


int main(){
    Solution sol;
    vector<int> v = sol.bubbleSort({7,23,6,7,1,6,78});
    for (auto itr = v.begin(); itr != v.end(); itr++){
        cout << *itr << " ";
    }
    return 0;
}
