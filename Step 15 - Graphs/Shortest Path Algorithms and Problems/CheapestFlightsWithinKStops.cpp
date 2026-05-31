class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto& e : flights){
            adj[e[0]].push_back({e[1], e[2]});
        }

        queue< pair<int,pair<int,int>> > q;
        vector<int> price(n, INT_MAX);

        q.push({0, {src, 0}});
        price[src] = 0;

        while (!q.empty()){
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            if (stops > k) continue;

            for (auto& [neigh, wt] : adj[node]){
                if (cost + wt < price[neigh] && stops <= k){
                    price[neigh] = cost + wt;
                    q.push({stops + 1, {neigh, price[neigh]}});
                }
            }
        }

        if (price[dst] == INT_MAX) return -1;

        return price[dst];
    }
};