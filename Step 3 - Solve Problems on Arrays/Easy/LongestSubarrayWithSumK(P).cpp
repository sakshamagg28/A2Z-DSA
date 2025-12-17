#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int longestSubarray(vector<int> nums, int k){
        int sum = 0;
        int length = 0;
        int maxLength = 0;
        for (int i = 0; i < (int)nums.size(); i++){
            sum = 0;
            for (int j = i; j < (int)nums.size(); j++){
                sum += nums[j];
                
                if (sum == k){
                    length = j-i+1;
                    if (length > maxLength) maxLength = length;
                }
            }
        }
        return maxLength;
    }
};


int main(){
    Solution sol;
    int result = sol.longestSubarray({10, 5, 2, 7, 1, 0, 9}, 15);
    cout << result;
    return 0;
}