class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool> &vis){
        vis[node] = true;
        for (auto it : adj[node]){
            if (!vis[it]){
                dfs (it, adj, vis);
            }
        }
    }

    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
        vector<int> adj[V];

        for (auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(V, false);
        int count = 0;

        for (int i = 0; i < V; i++){
            if (!vis[i]){
                dfs(i, adj, vis);
                count++;
            }
        }
        return count;
    }
};