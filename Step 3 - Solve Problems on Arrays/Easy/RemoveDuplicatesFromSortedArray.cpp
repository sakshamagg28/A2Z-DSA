class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> seen;
        for (int i = 0; i < nums.size(); i++){
            if (find(seen.begin(), seen.end(), nums[i]) == seen.end()){
                seen.push_back(nums[i]);
            }
        }
        
        for (int i = 0; i < seen.size(); i++){
            nums[i] = seen[i];
        }
        return seen.size();
    }
};