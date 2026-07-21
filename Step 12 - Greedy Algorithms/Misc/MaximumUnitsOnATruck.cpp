class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b){
            return a[1] > b[1];
        });

        int ans = 0;

        for (int i = 0; i < boxTypes.size(); i++){
            if (boxTypes[i][0] <= truckSize){
                ans += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else {
                ans += truckSize * boxTypes[i][1];
                break;
            }
        }

        return ans;
    }
};



// Alternate way to write
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             });

        int ans = 0;

        for (auto &box : boxTypes) {
            int take = min(truckSize, box[0]);
            ans += take * box[1];
            truckSize -= take;

            if (truckSize == 0)
                break;
        }

        return ans;
    }
};