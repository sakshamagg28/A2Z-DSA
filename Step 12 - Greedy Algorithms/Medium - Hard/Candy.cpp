class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> left(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        int ans = left[n - 1];
        int right = 1;

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right++;
            } else {
                right = 1;
            }

            ans += max(left[i], right);
        }

        return ans;
    }
};



// This is an optimized version of the above solution that uses O(1) space complexity.
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candies = 1;

        int up = 0, down = 0, peak = 0;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                up++;
                peak = up;
                down = 0;
                candies += 1 + up;
            }
            else if (ratings[i] == ratings[i - 1]) {
                up = down = peak = 0;
                candies += 1;
            }
            else {
                up = 0;
                down++;
                candies += 1 + down - (peak >= down ? 1 : 0);
            }
        }

        return candies;
    }
};