// DFS Approach

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



// BFS Approach

// class Solution {
// public:
//     bool bfs(int start, vector<int> adj[], vector<int>& vis) {
//         queue<pair<int, int>> q;   // {node, parent}
//         vis[start] = 1;
//         q.push({start, -1});

//         while (!q.empty()) {
//             auto [node, parent] = q.front();
//             q.pop();

//             for (int neighbour : adj[node]) {
//                 if (!vis[neighbour]) {
//                     vis[neighbour] = 1;
//                     q.push({neighbour, node});
//                 }
//                 else if (neighbour != parent) {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }

//     bool isCycle(int V, vector<int> adj[]) {
//         vector<int> vis(V, 0);

//         for (int i = 0; i < V; i++) {
//             if (!vis[i]) {
//                 if (bfs(i, adj, vis)) {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };