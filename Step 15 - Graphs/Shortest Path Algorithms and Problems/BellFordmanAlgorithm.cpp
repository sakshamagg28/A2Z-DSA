class Solution {
public:
	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e9);
        dist[S] = 0;

        for (int i = 0; i < V-1; i++){
            for (auto& e : edges){
                if (dist[e[0]] + e[2] < dist[e[1]]){
                    dist[e[1]] = dist[e[0]] + e[2];
                }
            }
        }

        for (auto& e : edges){
            if (dist[e[0]] + e[2] < dist[e[1]]){
                return {-1};
            }
        }

        return dist;
	}
};
