// =============================================================
// Approach 2: Reverse Graph + Kahn's Algorithm (Standard Interview Solution)
// Method: Reverse Graph + Topological Sort (BFS)
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
// Interview Status: Standard / Most Expected
// =============================================================

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<vector<int>> revGraph(n);
        vector<int> outdegree(n, 0);

        // Reverse graph and calculate outdegree
        for (int i = 0; i < n; i++) {
            outdegree[i] = graph[i].size();

            for (int nei : graph[i]) {
                revGraph[nei].push_back(i);
            }
        }

        queue<int> q;

        // Terminal nodes
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0)
                q.push(i);
        }

        vector<int> safe;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            safe.push_back(node);

            for (int prev : revGraph[node]) {
                outdegree[prev]--;

                if (outdegree[prev] == 0)
                    q.push(prev);
            }
        }

        sort(safe.begin(), safe.end());

        return safe;
    }
};





// =============================================================
// Approach : DFS + Cycle Detection
// Method: DFS + Visited + PathVisited + Safe Array
// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Interview Status: Standard DFS Solution
// =============================================================

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph,
             vector<int>& vis,
             vector<int>& pathVis,
             vector<int>& safe) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (int nei : graph[node]) {

            if (!vis[nei]) {
                if (dfs(nei, graph, vis, pathVis, safe))
                    return true;
            }
            else if (pathVis[nei]) {
                return true;
            }

            // Child is already processed and is unsafe
            if (!safe[nei])
                return true;
        }

        pathVis[node] = 0;
        safe[node] = 1;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> safe(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs(i, graph, vis, pathVis, safe);
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (safe[i])
                ans.push_back(i);
        }

        return ans;
    }
};