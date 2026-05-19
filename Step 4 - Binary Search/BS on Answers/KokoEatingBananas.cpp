class Solution {
public:
    bool canEat(vector<int>& piles, int h, int k){
        long long hours = 0;

        for (int i = 0; i < piles.size(); i++){
            hours += (piles[i] + k - 1)/k;
        }
        if (hours <= h) return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high){
            int mid = low + (high-low)/2;

            if (canEat(piles, h, mid)){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};