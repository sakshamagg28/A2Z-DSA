// =============================================================
// Approach 1: DFS + Edge Count (Standard Interview Solution)
// Method: DFS + Connectivity Check
// Time Complexity: O(V + E)
// Space Complexity: O(V + E) (Adjacency List + Recursion Stack)
// Interview Status: Standard / Most Expected
// =============================================================

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for (int nei : adj[node]) {
            if (!vis[nei])
                dfs(nei, adj, vis);
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        dfs(0, adj, vis);

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                return false;
        }

        return true;
    }
};




// =============================================================
// Approach 2: DFS + Cycle Detection
// Method: DFS + Parent Tracking
// Time Complexity: O(V + E)
// Space Complexity: O(V + E) (Adjacency List + Recursion Stack)
// Interview Status: Standard Alternative
// =============================================================

class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                if (!dfs(nei, node, adj, vis))
                    return false;
            }
            else if (nei != parent) {
                return false;
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);

        if (!dfs(0, -1, adj, vis))
            return false;

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                return false;
        }

        return true;
    }
};




// =============================================================
// Approach 3: BFS + Edge Count
// Method: BFS + Connectivity Check
// Time Complexity: O(V + E)
// Space Complexity: O(V + E) (Adjacency List + Queue)
// Interview Status: Standard BFS Solution
// =============================================================

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        queue<int> q;

        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nei : adj[node]) {
                if (!vis[nei]) {
                    vis[nei] = 1;
                    q.push(nei);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                return false;
        }

        return true;
    }
};




// =============================================================
// Approach 4: BFS + Cycle Detection
// Method: BFS + Parent Tracking
// Time Complexity: O(V + E)
// Space Complexity: O(V + E) (Adjacency List + Queue)
// Interview Status: Standard Alternative
// =============================================================

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        queue<pair<int, int>> q;

        q.push({0, -1});
        vis[0] = 1;

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for (int nei : adj[node]) {
                if (!vis[nei]) {
                    vis[nei] = 1;
                    q.push({nei, node});
                }
                else if (nei != parent) {
                    return false;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                return false;
        }

        return true;
    }
};




// =============================================================
// Approach 5: Union Find (DSU)
// Method: Path Compression + Union by Size
// Time Complexity: O(E · α(V)) ≈ O(E)
// Space Complexity: O(V)
// Special Feature: Best for Edge List Graphs
// Interview Status: Standard / Very Common
// =============================================================

class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return false;

        if (sz[u] < sz[v])
            swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;

        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &e : edges) {
            if (!unite(e[0], e[1]))
                return false;
        }

        return true;
    }
};