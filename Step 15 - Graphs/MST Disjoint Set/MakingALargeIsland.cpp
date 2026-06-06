class DisjointSet {
public:
    vector<int> size, parent;

    DisjointSet(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if (node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int uPar_u = findUPar(u);
        int uPar_v = findUPar(v);

        if (uPar_u == uPar_v) return;
        if (size[uPar_u] > size[uPar_v]){
            parent[uPar_v] = uPar_u;
            size[uPar_u] += size[uPar_v];
        }
        else {
            parent[uPar_u] = uPar_v;
            size[uPar_v] += size[uPar_u];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DisjointSet ds(n*n);

        bool zeroes = false;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 0) {
                    zeroes = true;
                    continue;
                }

                int dr[] = {1,-1,0,0};
                int dc[] = {0,0,1,-1};

                for (int k = 0; k < 4; k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        ds.unionBySize(n*i + j, n*nr + nc);
                    }
                }
            }
        }

        if (!zeroes) return n*n;

        int ans = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1) continue;

                unordered_set<int> parents;

                int dr[] = {1,-1,0,0};
                int dc[] = {0,0,1,-1};

                for (int k = 0; k < 4; k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        parents.insert(ds.findUPar(n*nr + nc));
                    }
                }

                int count = 1;
                for (int num : parents){
                    count += ds.size[num];
                }

                ans = max(ans, count);
            }
        }
        return ans;
    }
};