// Method : Meet in the Middle
// Time : O(N * 2^N)
// Space : O(2^N)

class Solution {
public:
    int minimumDifference(vector<int>& nums) {

        int n = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> L(n + 1), R(n + 1);

        for (int mask = 0; mask < (1 << n); mask++) {

            int cnt = 0;
            int sumL = 0;
            int sumR = 0;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    cnt++;
                    sumL += left[i];
                    sumR += right[i];
                }
            }

            L[cnt].push_back(sumL);
            R[cnt].push_back(sumR);
        }

        for (int i = 0; i <= n; i++)
            sort(R[i].begin(), R[i].end());

        int ans = INT_MAX;

        for (int cntLeft = 0; cntLeft <= n; cntLeft++) {

            int cntRight = n - cntLeft;

            for (int sumLeft : L[cntLeft]) {

                int target = total / 2 - sumLeft;

                auto &vec = R[cntRight];

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int sum = sumLeft + *it;
                    ans = min(ans, abs(total - 2 * sum));
                }

                if (it != vec.begin()) {
                    --it;
                    int sum = sumLeft + *it;
                    ans = min(ans, abs(total - 2 * sum));
                }
            }
        }

        return ans;
    }
};




// If equal size subsets are not required, then we can use the below approach for non-negative numbers.
// Method : Memoization
// State : dp[idx][target]
// Time : O(N*TotalSum)
// Space : O(N*TotalSum)

class Solution {
public:
    bool f(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0)
            return true;

        if (idx == 0)
            return nums[0] == target;

        if (dp[idx][target] != -1)
            return dp[idx][target];

        bool notTake = f(idx - 1, target, nums, dp);

        bool take = false;
        if (nums[idx] <= target)
            take = f(idx - 1, target - nums[idx], nums, dp);

        return dp[idx][target] = take || notTake;
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));

        for (int sum = 0; sum <= totalSum; sum++)
            f(n - 1, sum, nums, dp);

        int ans = INT_MAX;

        for (int sum = 0; sum <= totalSum; sum++) {
            if (dp[n - 1][sum]) {
                int diff = abs(totalSum - 2 * sum);
                ans = min(ans, diff);
            }
        }

        return ans;
    }
};
