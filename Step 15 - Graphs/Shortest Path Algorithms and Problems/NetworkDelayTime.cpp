class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for (auto& t : times){
            adj[t[0]].push_back({t[1], t[2]});
        }

        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> time(n+1, INT_MAX);
        
        pq.push({0, k});
        time[k] = 0;

        while(!pq.empty()){
            auto [t, node] = pq.top();
            pq.pop();
            if (t > time[node]) continue;

            for (auto& [neigh, wt] : adj[node]){
                int newTime = t + wt;

                if (newTime < time[neigh]){
                    time[neigh] = newTime;
                    pq.push({time[neigh], neigh});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++){
            if (time[i] == INT_MAX) return -1;
            ans = max(ans, time[i]);
        }

        return ans;
    }
};