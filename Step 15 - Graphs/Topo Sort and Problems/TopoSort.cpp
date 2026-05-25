// DFS Approach
class Solution{
public:
    void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& ans){
        vis[node] = 1;

        for (int neigh : adj[node]){
            if (!vis[neigh]){
                dfs(neigh, adj, vis, ans);
            }
        }

        ans.push_back(node);
    }
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> vis(V, 0);

        vector<int> ans;

        for (int i = 0; i < V; i++){
            if (!vis[i]){
                dfs(i, adj, vis, ans);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};




// BFS Approach
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++) {
        for (int neigh : adj[i]) {
            indegree[neigh]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int neigh : adj[node]) {
            indegree[neigh]--;
            if (indegree[neigh] == 0) {
                q.push(neigh);
            }
        }
    }

    return ans;
}