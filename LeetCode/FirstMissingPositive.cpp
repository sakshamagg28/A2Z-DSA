// Method: Cyclic Sort / Index Placement
// Time: O(n)
// Space: O(1)
// Standard Interview Solution

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n &&
                   nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};



// Index Marking (Also O(1) Extra Space)

// * Time: O(n)
// * Space: O(1)
// * Doesn’t use cyclic sort, but modifies signs in the array.

// Steps:
// 1. Replace all invalid numbers (<=0 or >n) with n+1.
// 2. For every value x in [1, n], mark index x-1 as negative.
// 3. The first positive index indicates the missing number.

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int &x : nums)
            if (x <= 0 || x > n)
                x = n + 1;

        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if (val <= n)
                nums[val - 1] = -abs(nums[val - 1]);
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                return i + 1;
        }

        return n + 1;
    }
};



// Hash Set (Simplest)

// * Time: O(n)
// * Space: O(n)
// * Easy to remember

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 1;
        while (st.count(ans))
            ans++;

        return ans;
    }
};