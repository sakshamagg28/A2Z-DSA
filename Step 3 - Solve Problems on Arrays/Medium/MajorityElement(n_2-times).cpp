class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }
        int maxCount = 0;
        int maxCountKey = -1;
        for (auto& p : count){
            if (p.second > maxCount){
                maxCount = p.second;
                maxCountKey = p.first;
            }
        }
        return maxCountKey;
    }
};