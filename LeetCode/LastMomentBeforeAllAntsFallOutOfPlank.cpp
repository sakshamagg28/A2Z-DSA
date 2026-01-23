class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLeft = 0;
        int minRight = n;
        
        if (!left.empty()) {
            for (int i = n; i >= 0; i--) {
                if (find(left.begin(), left.end(), i) != left.end()) {
                    maxLeft = i;
                    break;
                }
            }
        }
        if (!right.empty()) {
            for (int i = 0; i <= n; i++) {
                if (find(right.begin(), right.end(), i) != right.end()) {
                    minRight = i;
                    break;
                }
            }
        }
        
        return max(n - minRight, maxLeft);
    }
};
