class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n,-1));
        queue<pair<int,int>> q;
        
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (mat[i][j] == 0){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }

        while (!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for (int i=0 ; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                int distance = 0;
                if (nr>=0 && nr<m && nc>=0 && nc<n && dist[nr][nc] == -1){
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
        return dist;
    }
};