class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Smaller
        for (int i = 0; i < n; i++){
            while(!st.empty() && nums[i] <= nums[st.top()]){
                st.pop();
            }

            if (!st.empty()) left[i] = i - st.top();
            else left[i] = i + 1;

            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next smaller or equal
        for (int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[i] < nums[st.top()]){
                st.pop();
            }

            if (!st.empty()) right[i] = st.top() - i;
            else right[i] = n - i;

            st.push(i);
        }

        long long sumSubarrayMins = 0;

        for (int i = 0; i < n; i++){
            sumSubarrayMins += 1LL * nums[i] * left[i] * right[i];
        }

        while (!st.empty()) st.pop();

        // Previous Greater
        for (int i = 0; i < n; i++){
            while (!st.empty() && nums[i] >= nums[st.top()]){
                st.pop();
            }

            if(!st.empty()) left[i] = i - st.top();
            else left[i] = i + 1;

            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next greater or equal
        for (int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[i] > nums[st.top()]){
                st.pop();
            }

            if (!st.empty()) right[i] = st.top() - i;
            else right[i] = n - i;

            st.push(i);
        }

        long long sumSubarrayMaxs = 0;

        for (int i = 0; i < n; i++){
            sumSubarrayMaxs += 1LL * nums[i] * left[i] * right[i];
        }

        return sumSubarrayMaxs - sumSubarrayMins;
    }
};