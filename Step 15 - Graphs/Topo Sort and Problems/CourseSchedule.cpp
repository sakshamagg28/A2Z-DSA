class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        for (auto &e : prerequisites){
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }

        queue<int> q;
        for (int i=0; i<numCourses; i++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for (int neigh : adj[node]){
                indegree[neigh]--;
                if (indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
        return count == numCourses;
    }
};