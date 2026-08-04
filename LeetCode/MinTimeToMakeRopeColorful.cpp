// Approach 1: Grouping (Sum - Maximum) | Time: O(n) | Space: O(1) | Standard Interview Solution
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int sum = neededTime[0];
        int maxTime = neededTime[0];
        int ans = 0;

        for (int i = 1; i < n; i++){
            if (colors[i] == colors[i-1]){
                sum += neededTime[i];
                maxTime = max(maxTime, neededTime[i]);
            }
            else{
                ans += sum - maxTime;
                sum = neededTime[i];
                maxTime = neededTime[i];
            }
        }

        ans += sum - maxTime;

        return ans;
    }
};



// Approach 2: Greedy (Keep Maximum Removal Time) | Time: O(n) | Space: O(1) | Optimized One-Pass

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int mx = neededTime[0];

        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] != colors[i - 1]) {
                mx = neededTime[i];
            } else {
                ans += min(mx, neededTime[i]);
                mx = max(mx, neededTime[i]);
            }
        }

        return ans;
    }
};