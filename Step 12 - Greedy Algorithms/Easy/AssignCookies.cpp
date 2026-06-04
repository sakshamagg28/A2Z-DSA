class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int left = 0, right = 0;

        while(right < g.size() && left < s.size()){
            if (g[right] <= s[left]){
                right++;
            }
            left++;
        }
        return right;
    }
};