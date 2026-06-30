// Method : LIS + LDS DP (Recommended)
// State :
// lis[i] = LIS ending at i
// lds[i] = LDS starting at i
// Time : O(N²)
// Space : O(N)

class Solution {
public:
    int LongestBitonicSequence(vector<int> arr) {
        int n = arr.size();

        vector<int> lis(n, 1);
        vector<int> lds(n, 1);

        for (int i = 0; i < n; i++){
            for (int prev = 0; prev < i; prev++){
                if (arr[prev] < arr[i]){
                    lis[i] = max(lis[i], lis[prev] + 1);
                }
            }
        }

        for (int i = n-1; i >= 0; i--){
            for (int next = n-1; next > i; next--){
                if (arr[next] < arr[i]){
                    lds[i] = max(lds[i], lds[next] + 1);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++){
            if (lis[i] > 1 && lds[i] > 1){
                ans = max(ans, lis[i] + lds[i] - 1);
            }
        }

        return ans;
    }
};
