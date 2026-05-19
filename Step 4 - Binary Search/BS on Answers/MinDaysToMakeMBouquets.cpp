class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int days){
        int bouquets = 0;
        int cnt = 0;
        for (int i = 0; i < bloomDay.size(); i++){
            if (bloomDay[i] <= days){
                cnt++;
                if (cnt == k){
                    bouquets++;
                    cnt = 0;
                }
            }
            else{
                cnt = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > (long long)bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high){
            int mid = low + (high-low)/2;

            if (isPossible(bloomDay, m, k, mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};