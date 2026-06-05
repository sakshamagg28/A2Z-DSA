class Solution {
public:
    long long solve(vector<int>& bt) {
        //your code goes here
        int n = bt.size();
        sort(bt.begin(), bt.end());

        long long waitTime = 0;
        long long t = 0;
        
        for (int i = 0; i < n; i++){
            waitTime += t;
            t += bt[i];
        }

        return waitTime/n;
    }
};