// Method: Two Pointers (Forward Scan + Backward Scan)
// Time Complexity: O(M * N)
// Space Complexity: O(1)
// M = Length of s1, N = Length of s2
// Standard Interview Solution

class Solution {
public:
    string minWindow(string s1, string s2) {
        int m = s1.size(), n = s2.size();

        int start = -1;
        int minLen = INT_MAX;

        int i = 0;

        while (i < m) {
            int j = 0;

            // Forward scan: find a window containing s2 as a subsequence
            while (i < m) {
                if (s1[i] == s2[j])
                    j++;

                if (j == n)
                    break;

                i++;
            }

            if (i == m)
                break;

            // Backward scan: minimize the window
            int end = i;
            j = n - 1;

            while (j >= 0) {
                if (s1[i] == s2[j])
                    j--;

                i--;
            }

            i++;

            if (end - i + 1 < minLen) {
                minLen = end - i + 1;
                start = i;
            }

            // Start searching for the next window
            i++;
        }

        return start == -1 ? "" : s1.substr(start, minLen);
    }
};