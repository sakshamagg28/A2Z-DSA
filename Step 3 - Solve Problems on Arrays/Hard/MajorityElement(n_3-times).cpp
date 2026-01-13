class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m = nums.size()/3 + 1;
        vector<int> result;
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++){
            count[nums[i]]++;

            if (count[nums[i]] == m) result.push_back(nums[i]);
        }
        return result;
    }
};