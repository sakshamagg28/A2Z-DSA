// Method: Sliding Window
// Time Complexity: O(K)
// Space Complexity: O(1)
// Standard Interview Solution

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int currSum = 0;

        // Take first k cards
        for (int i = 0; i < k; i++)
            currSum += cardPoints[i];

        int maxSum = currSum;

        int left = k - 1;
        int right = n - 1;

        while (left >= 0) {
            currSum -= cardPoints[left--];
            currSum += cardPoints[right--];

            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};