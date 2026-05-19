class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int capacity){
        int d = 0;
        int space = capacity;
        for (int w : weights){
            if (w <= space){
                space -= w;
            }
            else {
                d++;
                space = capacity - w;
            }
        }
        if (space != capacity) d++;

        return d <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for (int num : weights){
            sum += num;
        }

        int low = *max_element(weights.begin(), weights.end());
        int high = sum;

        while (low <= high){
            int mid = low + (high - low)/2;

            if (isPossible(weights, days, mid)){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};