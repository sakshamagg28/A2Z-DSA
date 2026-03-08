// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int ans = 0, left = 0, sum = 0;
//         for (int right = 0; right < nums.size(); right++){
//             sum += nums[right];
//             while (sum > goal){
//                 sum -= nums[left];
//                 left++;
//             }
//             int left2 = left, sum2 = sum;
//             while (sum2 == goal && left2 <= right){
//                 ans++;
//                 sum2 -= nums[left2];
//                 left2++;
//             }
//         }
//         return ans;
//     }
// };


// OPTIMAL APPROACH
class Solution {
public:
    // Function to calculate number of subarrays with sum exactly equal to goal
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Return difference between subarrays with sum at most goal and at most (goal - 1)
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    // Helper function to compute number of subarrays with sum at most k
    int atMost(vector<int>& nums, int k) {
        // If k is negative, no such subarrays exist
        if (k < 0) return 0;

        int left = 0;
        int sum = 0;
        int count = 0;

        // Traverse the array using right pointer
        for (int right = 0; right < nums.size(); right++) {
            // Add current element to sum
            sum += nums[right];

            // Shrink the window from the left if sum exceeds k
            while (sum > k) {
                sum -= nums[left];
                left++;
            }

            // Add the number of valid subarrays ending at right
            count += (right - left + 1);
        }

        return count;
    }
};
