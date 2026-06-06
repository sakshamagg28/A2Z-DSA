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

int spanningTree(int V, vector<vector<int>>& edges) {

    sort(edges.begin(), edges.end());

    DisjointSet ds(V);

    int mstWeight = 0;

    for(auto &e : edges) {

        int wt = e[0];
        int u = e[1];
        int v = e[2];

        if(ds.findUPar(u) != ds.findUPar(v)) {

            mstWeight += wt;
            ds.unionBySize(u, v);
        }
    }

    return mstWeight;
}