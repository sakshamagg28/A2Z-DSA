// Method: Sliding Window + Hash Map
// Time Complexity: O(M + N)
// Space Complexity: O(N)
// M = Length of s, N = Length of t
// Standard Interview Solution

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;

        for (char ch : t)
            freq[ch]++;

        int required = t.size();
        int left = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right]] > 0)
                required--;

            freq[s[right]]--;

            while (required == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;

                if (freq[s[left]] > 0)
                    required++;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};