class Solution {
public:
    vector<int> replaceWithRank(vector<int>& arr) {
        // Your code goes here
        vector<int> ranksArray(arr.size());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (int i = 0; i < arr.size(); i++){
            pq.push({arr[i], i});
        }

        int rank = 0, prev = INT_MIN;
        while (!pq.empty()){
            auto top = pq.top();
            pq.pop();
            if (top.first > prev){
                rank++;
                prev = top.first;
            }
            ranksArray[top.second] = rank;
        }
        return ranksArray;
    }
};