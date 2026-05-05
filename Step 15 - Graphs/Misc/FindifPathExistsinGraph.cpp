class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        
        vector<int> vis(n);
        vector<vector<int>> adj(n);
        for (auto &e : edges){
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        }

        queue<int> q;
        q.push(source);
        vis[source] = 1;

        while(!q.empty()){
            int front = q.front();
            q.pop();
            for (int it : adj[front]){
                if (!vis[it]){
                    vis[it] = 1;
                    if (it == destination) return true;
                    q.push(it);
                }
            }
        }
        return false;
    }
};