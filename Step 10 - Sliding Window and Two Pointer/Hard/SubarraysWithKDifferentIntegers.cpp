// Method: Sliding Window + At Most K Trick
// Time Complexity: O(N)
// Space Complexity: O(K)
// Standard Interview Solution

class Solution {
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        int left = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            while (freq.size() > k) {
                freq[nums[left]]--;

                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);

                left++;
            }

            count += right - left + 1;
        }

        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};