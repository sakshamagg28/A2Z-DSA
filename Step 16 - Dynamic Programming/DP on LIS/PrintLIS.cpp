class Solution {
public:
    vector<int> longestIncreasingSubsequence(vector<int>& arr) {
        int n = arr.size();

        vector<int> dp(n, 1);
        vector<int> parent(n);

        int maxi = 1;
        int lastIdx = 0;

        for (int i = 0; i < n; i++){
            parent[i] = i;

            for (int prev = 0; prev < i; prev++){
                if (arr[prev] < arr[i] && dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev] + 1;
                    parent[i] = prev;
                }
            }
            
            if (dp[i] > maxi){
                maxi = dp[i];
                lastIdx = i;
            }
        }

        vector<int> lis;

        while (parent[lastIdx] != lastIdx){
            lis.push_back(arr[lastIdx]);
            lastIdx = parent[lastIdx];
        }

        lis.push_back(arr[lastIdx]);

        reverse(lis.begin(), lis.end());

        return lis;
    }
};