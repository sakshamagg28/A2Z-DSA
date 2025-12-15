#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> nums) {
        int count = 0;
        int maxCount = count;
        for (int i = 0; i < (int)nums.size()-1; i++){
            if (nums[i+1] == 1 && nums[i] == 1){
                count++;
            }
            else if (nums[i+1] == 1 && nums[i] == 0){
                count = 1;
            }
            else if (nums[i+1] == 0){
                count = 0;
            }
            if (count > maxCount) maxCount = count;
        }
        return maxCount;
    }
};

int main(){
    Solution sol;
    int result = sol.findMaxConsecutiveOnes({0, 1, 1,1,1, 0, 0, 1});
    cout << result;
    return 0;
}