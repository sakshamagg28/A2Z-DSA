class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans= 0;

        queue<pair<int,int>> q;

        for (int i = 0; i < m; i++){
            if (grid[i][0] == 1){
                q.push({i, 0});
                grid[i][0] = -1;
            }
            if (grid[i][n-1] == 1){
                q.push({i, n-1});
                grid[i][n-1] = -1;
            }
        }

        for (int j = 0; j < n; j++){
            if (grid[0][j] == 1){
                q.push({0, j});
                grid[0][j] = -1;
            }
            if (grid[m-1][j] == 1){
                q.push({m-1, j});
                grid[m-1][j] = -1;
            }
        }

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                    q.push({nr, nc});
                    grid[nr][nc] = -1;
                }
            }
        }

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};