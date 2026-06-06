class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (time > dist[r][c]) continue;

            if (r == n-1 && c == n-1) return time;

            int dr[] = {1,-1,0,0};
            int dc[] = {0,0,1,-1};

            for (int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n){
                    int newTime = max(grid[nr][nc], time);
                    
                    if(newTime < dist[nr][nc]){
                        dist[nr][nc] = newTime;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};