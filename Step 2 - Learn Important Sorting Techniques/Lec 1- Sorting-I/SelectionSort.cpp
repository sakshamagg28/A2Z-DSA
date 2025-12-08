#include "all.h"
using namespace std;

class Solution {
public:
    vector<int> selectionSort(vector<int> nums) {  
        for (int i = 0; i < nums.size(); i++){
            for (int j = i; j < nums.size(); j++){
                if (nums[j] < nums[i]) swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};

int main(){
    Solution sol;
    vector<int> v = sol.selectionSort({7,23,6,7,1,6,78}); 
    for (auto itr = v.begin(); itr != v.end(); itr++){
        cout << *itr << " ";
    }
    return 0;
}
