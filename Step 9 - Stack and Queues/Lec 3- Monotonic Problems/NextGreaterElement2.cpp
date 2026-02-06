class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> result(nums.size());
        for (int i = 2*nums.size()-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i % nums.size()]){
                st.pop();
            }
            if (st.empty()) {
                result[i % nums.size()] = -1;
            }
            else {
                result[i % nums.size()] = st.top();
            }
            st.push(nums[i % nums.size()]);
        }
        return result;
    }
};