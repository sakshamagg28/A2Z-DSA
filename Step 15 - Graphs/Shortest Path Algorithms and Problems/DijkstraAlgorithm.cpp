class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> edges, int S) {
        vector<vector<pair<int,int>>> adj(V);

        for (auto& e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> dist(V, 1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[S] = 0;
        pq.push({0, S});

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            if (d > dist[node]) continue;

            for (auto& [neigh, wt] : adj[node]){
                if (d + wt < dist[neigh]){
                    dist[neigh] = d + wt;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        return dist;
    }
};