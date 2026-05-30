class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
        vector<vector<int>> adj(N);

        for (auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> dist(N, -1);
        dist[0] = 0;
        
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for (int neigh : adj[node]){
                if (dist[neigh] == -1){
                    dist[neigh] = dist[node] + 1;
                    q.push(neigh);
                }
            }
        }
        return dist;
    }
};
