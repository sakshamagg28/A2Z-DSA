class Solution {
public:
	void shortestDistance(vector<vector<int>>&matrix) {
        int V = matrix.size();

        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                if (matrix[i][j] == -1) matrix[i][j] = 1e9;
                if (i == j) matrix[i][j] = 0;
            }
        }

        for (int k = 0; k < V; k++){
            for (int i = 0; i < V; i++){
                for (int j = 0; j < V; j++){
                    if (matrix[i][k] + matrix[k][j] < matrix[i][j]){
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }

        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                if (matrix[i][j] == 1e9) matrix[i][j] = -1;
            }
        }
	}
};