class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> rev(n);
        vector<int> outdegree(n);

        for (int i=0; i<n; i++){
            outdegree[i] = graph[i].size();

            for (int neigh : graph[i]){
                rev[neigh].push_back(i);
            }
        }

        queue<int> q;
        for (int i=0; i<n; i++){
            if (outdegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;

        while (!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int neigh : rev[node]){
                outdegree[neigh]--;

                if (outdegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};