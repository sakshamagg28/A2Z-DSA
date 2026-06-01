class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);

        for (auto& e : roads){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        priority_queue< pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>> > pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n);

        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            long long t = it.first;
            int node = it.second;

            if (t > dist[node]) continue;

            for (auto& [neigh, wt] : adj[node]){
                long long newDist = t + wt;
                if (newDist < dist[neigh]){
                    dist[neigh] = newDist;
                    ways[neigh] = ways[node];
                    pq.push({dist[neigh], neigh});
                }
                else if (newDist == dist[neigh]){
                    ways[neigh] = (ways[neigh] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};