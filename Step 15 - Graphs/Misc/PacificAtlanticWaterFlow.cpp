class Solution {
public:
    int m, n;
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& vis){
        vis[r][c] = true;

        for (int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n 
                && heights[nr][nc] >= heights[r][c] 
                && !vis[nr][nc]){
                
                dfs(nr, nc, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++){
            dfs(i, 0, heights, pacific);
        }

        for (int j = 0; j < n; j++){
            dfs(0, j, heights, pacific);
        }

        for (int i = 0; i < m; i++){
            dfs(i, n-1, heights, atlantic);
        }

        for (int j = 0; j < n; j++){
            dfs(m-1, j, heights, atlantic);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};