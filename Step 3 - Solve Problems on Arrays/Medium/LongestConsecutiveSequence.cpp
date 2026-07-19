// Method: Hash Set
// Time: O(n)
// Space: O(n)
// Standard Interview Solution

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int num : st) {
            // Start of a sequence
            if (!st.count(num - 1)) {
                int curr = num;
                int len = 1;

                while (st.count(curr + 1)) {
                    curr++;
                    len++;
                }

                longest = max(longest, len);
            }
        }

        return longest;
    }
};



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 0) return 0;
        int length = 1 , maxLength = 1;
        for (int i = 0; i < nums.size()-1; i++){
            if (nums[i+1] == nums[i]) continue;
            if (nums[i+1] - nums[i] == 1){
                length++;
            }
            else{
                length = 1;
            }
            if (length > maxLength) maxLength = length;
        }
        return maxLength;
    }
};