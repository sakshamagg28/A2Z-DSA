// Method: Prefix Sum + Hash Map
// Time: O(n)
// Space: O(n)
// Standard Interview Solution

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {
            prefixSum += num;

            if (mp.count(prefixSum - k))
                count += mp[prefixSum - k];

            mp[prefixSum]++;
        }

        return count;
    }
};




class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int index = 0, sum = 0, count = 0;
        for (int i = 0; i < nums.size(); i++){
            sum = 0;
            for (int j = i; j < nums.size(); j++){
                sum += nums[j];

                if (sum == k){
                    count += 1;
                }
            }
        }
        return count;
    }
    
};