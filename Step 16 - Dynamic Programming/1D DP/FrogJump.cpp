class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();

        if (n == 1) return 0;

        int prev1 = abs(heights[1] - heights[0]);
        int prev2 = 0;
        int curr = prev1;

        for (int i = 2; i < n; i++){
            int oneStep = prev1 + abs(heights[i] - heights[i - 1]);

            int twoStep = prev2 + abs(heights[i] - heights[i - 2]);

            curr = min(oneStep, twoStep);

            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};