//==============================================================//
// Method 1 : Recursion
// State : f(day,last)
// Time Complexity : O(3^N)
// Space Complexity : O(N)
//==============================================================//

class Solution {
public:
    int f(int day, int last, vector<vector<int>>& points) {
        if (day == 0) {
            int maxi = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last)
                    maxi = max(maxi, points[0][task]);
            }
            return maxi;
        }

        int maxi = 0;

        for (int task = 0; task < 3; task++) {
            if (task != last)
                maxi = max(maxi, points[day][task] + f(day - 1, task, points));
        }

        return maxi;
    }

    int ninjaTraining(vector<vector<int>>& points) {
        int n = points.size();
        return f(n - 1, 3, points);
    }
};

//==============================================================//
// Method 2 : Memoization
// State : dp[day][last]
// Time Complexity : O(N)
// Space Complexity : O(N)
//==============================================================//

class Solution {
public:
    int f(int day, int last, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if (day == 0){
            int maxi = 0;
            for (int task = 0; task < 3; task++){
                if (task != last){
                    maxi = max(maxi, matrix[0][task]);
                }
            }
            return dp[0][last] = maxi;
        }

        if (dp[day][last] != -1) return dp[day][last];

        int maxi = 0;
        for (int task = 0; task < 3; task++){
            if (task != last){
                maxi = max(maxi, matrix[day][task] + f(day-1, task, matrix, dp));
            }
        }

        return dp[day][last] = maxi;
    }

    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(4, -1));

        return f(n-1, 3, matrix, dp);
    }
};

//==============================================================//
// Method 3 : Tabulation (Last Activity State)
// State : dp[day][last]
// Time Complexity : O(N)
// Space Complexity : O(N)
//==============================================================//

class Solution {
public:
    int ninjaTraining(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<int>> dp(n, vector<int>(4));

        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

        for (int day = 1; day < n; day++) {
            for (int last = 0; last < 4; last++) {
                dp[day][last] = 0;

                for (int task = 0; task < 3; task++) {
                    if (task != last)
                        dp[day][last] = max(dp[day][last],
                                            points[day][task] + dp[day - 1][task]);
                }
            }
        }

        return dp[n - 1][3];
    }
};

//==============================================================//
// Method 4 : Space Optimized (Last Activity State)
// Time Complexity : O(N)
// Space Complexity : O(1)
//==============================================================//

class Solution {
public:
    int ninjaTraining(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> prev(4);

        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max({points[0][0], points[0][1], points[0][2]});

        for (int day = 1; day < n; day++) {
            vector<int> curr(4);

            for (int last = 0; last < 4; last++) {
                for (int task = 0; task < 3; task++) {
                    if (task != last)
                        curr[last] = max(curr[last],
                                         points[day][task] + prev[task]);
                }
            }

            prev = curr;
        }

        return prev[3];
    }
};

//==============================================================//
// Method 5 : Tabulation (Activity State)
// State : dp[day][activity]
// Time Complexity : O(N)
// Space Complexity : O(N)
//==============================================================//

class Solution {
public:
    int ninjaTraining(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<int>> dp(n, vector<int>(3));

        dp[0][0] = points[0][0];
        dp[0][1] = points[0][1];
        dp[0][2] = points[0][2];

        for (int i = 1; i < n; i++) {
            dp[i][0] = points[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = points[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = points[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
        }

        return max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    }
};

//==============================================================//
// Method 6 : Space Optimized (Activity State)
// Time Complexity : O(N)
// Space Complexity : O(1)
//==============================================================//

class Solution {
public:
    int ninjaTraining(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> prev = points[0];

        for (int i = 1; i < n; i++) {
            vector<int> curr(3);

            curr[0] = points[i][0] + max(prev[1], prev[2]);
            curr[1] = points[i][1] + max(prev[0], prev[2]);
            curr[2] = points[i][2] + max(prev[0], prev[1]);

            prev = curr;
        }

        return max({prev[0], prev[1], prev[2]});
    }
};