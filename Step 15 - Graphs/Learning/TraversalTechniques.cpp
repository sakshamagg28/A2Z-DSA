class Solution {
public:
    void dfs(int V, vector<int> adj[], vector<int>& vis, vector<int>& res){
        vis[V] = 1;
        res.push_back(V);
        for (auto it : adj[V]){
            if (!vis[it]){
                dfs(it, adj, vis, res);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V,0) , res;
        dfs (0, adj, vis, res);
        return res;
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V,0) , res;
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while (!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);

            for (int neigh : adj[node]){
                if (!vis[neigh]){
                    vis[neigh] = 1;
                    q.push(neigh);
                }
            }
        }
        return res;
    }
};
