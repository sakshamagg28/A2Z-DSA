class Solution {
public:
    int maxLen(vector<int>& arr, int n) {
        unordered_map<long long, int> firstIndex;
        long long prefix = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            prefix += arr[i];

            if (prefix == 0) {
                maxLen = i + 1;
            }

            if (firstIndex.find(prefix) != firstIndex.end()) {
                maxLen = max(maxLen, i - firstIndex[prefix]);
            } else {
                firstIndex[prefix] = i;
            }
        }

        return maxLen;
    }
};