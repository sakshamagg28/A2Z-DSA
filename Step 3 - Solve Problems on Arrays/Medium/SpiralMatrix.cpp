class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();

        vector<int> spiral;
        int k = 0, i = 0, j = 0;
        while (spiral.size() != m*n){
            for (int j = 0+k; j < n-k; j++){
                spiral.push_back(matrix[0+k][j]);
            }
            for (int i = 1+k; i < m-k; i++){
                spiral.push_back(matrix[i][n-1-k]);
            }
            if (m-k-1 > k){
                for (int j = n-2-k; j >= k; j--){
                    spiral.push_back(matrix[m-1-k][j]);
                }
            }
            if (n-k-1 > k){
                for (int i = m-2-k; i >= k+1; i--){
                    spiral.push_back(matrix[i][0+k]);
                }
            }
            k++;
        }
        return spiral;
    }
};