class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.size();

        vector<vector<int>> ans;
        int start = 0, end = 0, count = 1;

        for (int i = 1; i < n; i++){
            if (s[i] == s[i-1]){
                count++;
            }
            else{
                if (count >= 3){
                    end = i - 1;
                    ans.push_back({start, end});
                }

                count = 1;
                start = i;
            }
        }

        if (count >= 3) {
            end = n - 1;
            ans.push_back({start, end});
        }

        return ans;
    }
};



// ChatGPT's alternative solution
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int start = 0, n = s.size();

        for (int i = 1; i <= n; i++) {
            if (i == n || s[i] != s[i - 1]) {
                if (i - start >= 3)
                    ans.push_back({start, i - 1});
                start = i;
            }
        }

        return ans;
    }
};