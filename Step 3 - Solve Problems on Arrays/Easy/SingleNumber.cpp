#include <iostream>
#include <vector>
using namespace std;

class Solution{    
public:    
    int singleNumber(vector<int> nums){
        //your code goes here
        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> count(maxElement + 1, 0);

        for (int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }
        for (int j = 0; j < count.size(); j++){
            if (count[j] == 1){
                return j;
                break;
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    int result = sol.singleNumber({1, 2, 2, 4, 3, 1, 4});
    cout << result;
    return 0;
}