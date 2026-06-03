class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> vis(V);
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        
        pq.push({0, {0, -1}});

        int sum = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second.first;
            int parent = it.second.second;

            if (vis[node] == 1) continue;
            vis[node] = 1;
            sum += wt;

            for (auto& e : adj[node]){
                int neigh = e[0];
                int edW = e[1];

                if (!vis[neigh]){
                    pq.push({edW, {neigh, node}});
                }
            }
        }
        return sum;
    }
};
