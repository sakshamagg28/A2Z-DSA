class Solution {
public:
    static bool comparator(pair<long long, long long> a, pair<long long, long long> b){
        if ((double)a.first/a.second > (double)b.first/b.second){
            return true;
        }
        return false;
    }

    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        // Your code goes here
        int n = val.size();

        vector<pair<long long, long long>> arr(n);
        for (int i=0; i<n; i++){
            arr[i] = {val[i], wt[i]};
        }
        sort(arr.begin(), arr.end(), comparator);

        double totVal = 0;
        
        for (int i = 0; i < n; i++){
            long long val = arr[i].first;
            long long wt = arr[i].second;
            if (capacity >= wt){
                totVal += val;
                capacity -= wt;
            }
            else{
                totVal += (double)val/wt * capacity;
                break;
            }
        }

        return totVal;
    }
};


// Optimized version without using pairs and custom comparator
class Solution {
public:
    double fractionalKnapsack(vector<long long>& val,
                              vector<long long>& wt,
                              long long capacity) {

        int n = val.size();

        vector<int> idx(n);
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return val[a] * wt[b] > val[b] * wt[a];
        });

        double totalValue = 0.0;

        for (int i : idx) {
            if (capacity == 0) break;

            if (wt[i] <= capacity) {
                totalValue += val[i];
                capacity -= wt[i];
            } else {
                totalValue += (double)val[i] * capacity / wt[i];
                break;
            }
        }

        return totalValue;
    }
};