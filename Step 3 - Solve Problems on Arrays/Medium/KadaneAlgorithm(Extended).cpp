#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int printMaxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, sum = 0;
        int startCurrent= -1, startMax = -1, endMax = -1;

        for (int i = 0; i < (int)nums.size(); i++){
            if (sum == 0){
                startCurrent = i;
            }

            sum += nums[i];

            if (sum > maxSum) {
                maxSum = sum;
                startMax = startCurrent;
                endMax = i;
            }
            if (sum < 0){
                sum = 0;
            }
        }

        for (auto it = nums.begin() + startMax; it <= nums.begin() + endMax ; it++){
            cout << *it << " " << endl;
        }

        return maxSum;
    }
};


int main() {
    vector<int> arr = { 2, 3, 5, -2, 7, -4 };
    Solution sol;
    int maxSum = sol.printMaxSubArray(arr);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
