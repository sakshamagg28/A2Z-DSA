class Solution {
public:
    int kthSmallestElement(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for (int i = 0; i < k; i++){
            pq.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++){
            if (nums[i] < pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};