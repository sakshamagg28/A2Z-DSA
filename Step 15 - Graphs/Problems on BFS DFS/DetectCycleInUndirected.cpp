class Solution{
public:
    bool dfs(int node, int parent, vector<int> adj[], vector<int>& vis){
        vis[node] = 1;

        for (int neigh : adj[node]){
            if (!vis[neigh]){
                if (dfs(neigh, node, adj, vis)){
                    return true;
                }
            }
            else if (neigh != parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V);

        for (int i = 0; i < V; i++){
            if (!vis[i] && dfs(i, -1, adj, vis)){
                return true;
            }
        }
        return false;
    }
};