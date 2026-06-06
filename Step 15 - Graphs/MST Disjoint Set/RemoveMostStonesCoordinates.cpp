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

    bool find(int u, int v) {
        int uPar_u = findUPar(u);
        int uPar_v = findUPar(v);

        if (uPar_u == uPar_v) return true;
        else return false;
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int maxRow = 0;
        int maxCol = 0;
        for (auto& s : stones){
            maxRow = max(maxRow, s[0]);
            maxCol = max(maxCol, s[1]);
        }

        DisjointSet dsu(maxRow + maxCol + 2);

        unordered_set<int> stoneNodes;
        for (auto& s : stones){
            int nodeRow = s[0];
            int nodeCol = maxRow + 1 + s[1];
            dsu.unionBySize(nodeRow, nodeCol);
            stoneNodes.insert(nodeRow);
            stoneNodes.insert(nodeCol);
        }

        int cntComp = 0;
        for (int node : stoneNodes){
            if (dsu.findUPar(node) == node) cntComp++;
        }

        return n - cntComp;
    }
};