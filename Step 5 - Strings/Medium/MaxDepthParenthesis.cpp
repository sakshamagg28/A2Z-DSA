class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int maxCnt = 0;
        for (char c : s){
            if (c == '('){
                cnt++;
            }
            else if (c == ')'){
                cnt--;
            }

            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};