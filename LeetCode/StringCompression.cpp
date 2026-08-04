// Optimal Solution O(n) time and O(1) space
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;
        int i = 0;

        while (i < n){
            int j = i;

            while (j < n && chars[j] == chars[i]){
                j++;
            }

            chars[write++] = chars[i];

            int cnt = j - i;

            if (cnt > 1){
                string s = to_string(cnt);
                for (char c : s){
                    chars[write++] = c;
                }
            }

            i = j;
        }

        return write;
    }
};



// My Solution
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string ans = "";

        int count = 1;

        for (int i = 1; i < n; i++){
            if (chars[i] == chars[i-1]){
                count++;
            }
            else{
                ans += chars[i-1];

                if(count > 1){
                    ans += to_string(count);
                }

                count = 1;
            }
        }

        ans += chars[n-1];

        if(count > 1){
            ans += to_string(count);
        }

        for (int i = 0; i < ans.size(); i++)
            chars[i] = ans[i];

        return ans.size();
    }
};