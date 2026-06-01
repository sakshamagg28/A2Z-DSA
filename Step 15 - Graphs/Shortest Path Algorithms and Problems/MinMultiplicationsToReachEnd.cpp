class Solution{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end) {
        const int MOD = 1e5;

        queue< pair<int,int> > pq;
        vector<int> dist(100000, INT_MAX);

        pq.push({0, start});
        dist[start] = 0;

        while (!pq.empty()){
            auto [steps, node] = pq.front();
            pq.pop();

            if (node == end) return steps;

            for (int& num : arr){
                int newNode = (node * num) % MOD;
                int newDist = steps + 1;

                if (newDist < dist[newNode]){
                    dist[newNode] = newDist;
                    pq.push({dist[newNode], newNode});
                }
            }
        }
        return -1;
    }
};


// Priority Queue Version (Dijkstra's Algorithm) - although not required
class Solution{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end) {
        const int MOD = 1e5;

        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> dist(100000, INT_MAX);

        pq.push({0, start});
        dist[start] = 0;

        while (!pq.empty()){
            auto [steps, node] = pq.top();
            pq.pop();

            if (steps > dist[node]) continue;

            for (int& num : arr){
                int newNode = (node * num) % MOD;
                int newDist = steps + 1;

                if (newDist < dist[newNode]){
                    dist[newNode] = newDist;
                    pq.push({dist[newNode], newNode});
                }
            }
        }
        return dist[end];
    }
};
