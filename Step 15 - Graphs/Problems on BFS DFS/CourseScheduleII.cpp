class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;

        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for (auto& e : prerequisites){
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        while (!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int neigh : adj[node]){
                indegree[neigh]--;
                if (indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        if (ans.size() != numCourses) return {};
        
        return ans;
    }
};