// Approach: Greedy (Last Occurrence)
// Time: O(n)
// Space: O(1)

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26);

        // Store last occurrence of each character
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        vector<int> ans;
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']);

            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};




// Approach: Character Intervals + Merge Intervals
// Time: O(n + k log k)
// Space: O(k)

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> mp;

        // Store first and last occurrence
        for (int i = 0; i < s.size(); i++) {
            if (mp.count(s[i]))
                mp[s[i]].second = i;
            else
                mp[s[i]] = {i, i};
        }

        // Build intervals
        vector<pair<int, int>> intervals;
        for (auto &it : mp)
            intervals.push_back(it.second);

        // Sort by first occurrence
        sort(intervals.begin(), intervals.end());

        vector<int> ans;

        int start = intervals[0].first;
        int end = intervals[0].second;

        // Merge intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].first <= end)
                end = max(end, intervals[i].second);
            else {
                ans.push_back(end - start + 1);
                start = intervals[i].first;
                end = intervals[i].second;
            }
        }

        ans.push_back(end - start + 1);

        return ans;
    }
};