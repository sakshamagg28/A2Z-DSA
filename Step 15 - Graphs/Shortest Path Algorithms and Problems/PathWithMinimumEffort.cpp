class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0,0}});

        while (!pq.empty()){
            auto [effort, cell] = pq.top();
            pq.pop();
            auto [r, c] = cell;

            if (r == m-1 && c == n-1) return effort;

            for (int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n){
                    int newEffort = max(abs(heights[nr][nc] - heights[r][c]), effort);
                    if (newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};