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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DisjointSet dsu(n);

        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++){
            for (int j = 1; j < accounts[i].size(); j++){
                if (mp.find(accounts[i][j]) == mp.end()){
                    mp[accounts[i][j]] = i;
                }
                else{
                    dsu.unionBySize(mp[accounts[i][j]], i);
                }
            }
        }


        vector<vector<string>> ans(n);
        for (int i = 0; i < n; i++){
            ans[i].push_back(accounts[i][0]);
        }

        for (auto& [s, node] : mp){
            int root = dsu.findUPar(node);

            ans[root].push_back(s);
        }

        vector<vector<string>> res;

        for (int i = 0; i < n; i++){
            if (ans[i].size() > 1){
                sort(ans[i].begin() + 1, ans[i].end());
                res.push_back(ans[i]);
            }
        }

        return res;
    }
};