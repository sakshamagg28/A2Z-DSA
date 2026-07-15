// =============================================================
// Approach 2: Kahn's Algorithm
// Method: BFS + Topological Sort
// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Special Feature: Detects Cycle using Topological Ordering
// Interview Status: Standard Alternative
// =============================================================

class Solution {
public:
    bool isCyclic(int V, vector<vector<int>>& adj) {

        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (int nei : adj[i])
                indegree[nei]++;
        }

        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            count++;

            for (int nei : adj[node]) {
                indegree[nei]--;

                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        return count != V;
    }
};




// =============================================================
// Approach 1: DFS + Recursion Stack (Standard Interview Solution)
// Method: DFS + Path Visited Array
// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Interview Status: Standard / Most Expected
// =============================================================

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& pathVis) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (int nei : adj[node]) {

            if (!vis[nei]) {
                if (dfs(nei, adj, vis, pathVis))
                    return true;
            }
            else if (pathVis[nei]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& adj) {

        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis))
                    return true;
            }
        }

        return false;
    }
};