class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); i++){
            if (result.empty() || result.back()[1] < intervals[i][0]){
                result.push_back({intervals[i][0], intervals[i][1]});
            }
            else{
                result.back()[1] = max (result.back()[1], intervals[i][1]);
            }
        }
        return result;
    }
};