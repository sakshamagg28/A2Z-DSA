class Solution {
    public:
    void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<int>& vis, stack<int>& st){
        vis[node] = 1;
        for (auto& neigh : adj[node]){
            if (!vis[neigh.first]){
                dfs(neigh.first, adj, vis, st);
            }
        }
        st.push(node);
    }
    vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {
        vector<vector<pair<int,int>>> adj(N);

        for (auto& e : edges){
            adj[e[0]].push_back({e[1], e[2]});
        }

        stack<int> st;
        vector<int> vis(N);
        for (int i = 0; i < N; i++){
            if (!vis[i]){
                dfs(i, adj, vis, st);
            }
        }

        vector<int> dist(N, INT_MAX);
        dist[0] = 0;

        while (!st.empty()){
            int node = st.top();
            st.pop();
            if (dist[node] == INT_MAX) continue;

            for (auto& neigh : adj[node]){
                dist[neigh.first] = min(dist[neigh.first], dist[node] + neigh.second);
            }
        }

        for (int i = 0; i< N; i++){
            if (dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};

