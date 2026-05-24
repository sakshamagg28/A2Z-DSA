class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>> &vis){
        int m = grid.size(), n = grid[0].size();

        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != '1' || vis[row][col]){
            return;
        }

        vis[row][col] = 1;

        dfs(grid, row - 1, col, vis);
        dfs(grid, row + 1, col, vis);
        dfs(grid, row, col - 1, vis);
        dfs(grid, row, col + 1, vis);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n));

        int ans = 0;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1' && !vis[i][j]){
                    dfs(grid, i, j, vis);
                    vis[i][j] = 1;
                    ans++;
                }
            }
        }
        return ans;

    }
};