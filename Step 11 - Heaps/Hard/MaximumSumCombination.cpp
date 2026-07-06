// Method: Sorting + Max Heap + Hash Set
// Time Complexity: O(N log N + K log K)
// Space Complexity: O(K)
// Standard Interview Solution

class Solution {
public:
    vector<int> maxCombinations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> vis;

        pq.push({nums1[n - 1] + nums2[n - 1], {n - 1, n - 1}});
        vis.insert({n - 1, n - 1});

        vector<int> ans;

        while (k--) {
            auto cur = pq.top();
            pq.pop();

            int sum = cur.first;
            int i = cur.second.first;
            int j = cur.second.second;

            ans.push_back(sum);

            if (i - 1 >= 0 && !vis.count({i - 1, j})) {
                pq.push({nums1[i - 1] + nums2[j], {i - 1, j}});
                vis.insert({i - 1, j});
            }

            if (j - 1 >= 0 && !vis.count({i, j - 1})) {
                pq.push({nums1[i] + nums2[j - 1], {i, j - 1}});
                vis.insert({i, j - 1});
            }
        }

        return ans;
    }
};