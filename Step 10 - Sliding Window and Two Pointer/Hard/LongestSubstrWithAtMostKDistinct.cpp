// Method: Sliding Window + Hash Map
// Time Complexity: O(N)
// Space Complexity: O(K)
// Standard Interview Solution

class Solution {
public:
    int longestKSubstr(string s, int k) {
        unordered_map<char, int> freq;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;

            while (freq.size() > k) {
                freq[s[left]]--;

                if (freq[s[left]] == 0)
                    freq.erase(s[left]);

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};