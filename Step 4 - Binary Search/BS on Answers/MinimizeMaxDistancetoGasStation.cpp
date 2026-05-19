class Solution {
public:
    bool isPossible(vector<int> &arr, int k, long double maxDist){
        int needed = 0;
        for (int i = 0; i < arr.size()-1; i++){
            long double gap = arr[i+1]-arr[i];
            int stations = gap/maxDist;

            if (fmod(gap, maxDist) == 0) stations--;

            needed += stations;
        }
        return needed <= k;
    }

    long double minimiseMaxDistance(vector<int> &arr, int k) {
        long double low = 0;
        long double high = 0;

        for (int i = 0; i < arr.size()-1; i++){
            long double dist = arr[i+1] - arr[i];
            if (dist > high) high = dist;
        }

        while (high - low > 1e-6){
            long double mid = low + (high-low)/2;

            if (isPossible(arr, k, mid)){
                high = mid ;
            }
            else low = mid;
        }
        return low;
    }
};