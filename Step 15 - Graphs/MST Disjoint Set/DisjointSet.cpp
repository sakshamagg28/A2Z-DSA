class DisjointSet {
public:
    vector<int> rank, size, parent;

    DisjointSet(int n) {
        rank.resize(n+1, 0);
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

    void unionByRank(int u, int v) {
        int uPar_u = findUPar(u);
        int uPar_v = findUPar(v);

        if (uPar_u == uPar_v) return;
        if (rank[uPar_u] > rank[uPar_v]){
            parent[uPar_v] = uPar_u;
        }
        else if (rank[uPar_u] < rank[uPar_v]){
            parent[uPar_u] = uPar_v;
        }
        else {
            parent[uPar_v] = uPar_u;
            rank[uPar_u]++; 
        }
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
