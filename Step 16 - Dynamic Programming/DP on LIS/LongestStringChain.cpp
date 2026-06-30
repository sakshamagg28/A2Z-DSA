// Method 1 : Recursion
// State : f(idx,prevIdx)
// Time : Exponential
// Space : O(N)
// Restriction : Not practical for large constraints

class Solution {
public:
    static bool comp(string& a, string& b) {
        return a.size() < b.size();
    }

    bool check(string& longer, string& shorter) {

        if (longer.size() != shorter.size() + 1)
            return false;

        int i = 0, j = 0;

        while (i < longer.size()) {

            if (j < shorter.size() && longer[i] == shorter[j]) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }

        return j == shorter.size();
    }

    int f(int idx, int prevIdx, vector<string>& words) {

        if (idx == words.size())
            return 0;

        int notTake = f(idx + 1, prevIdx, words);

        int take = 0;
        if (prevIdx == -1 || check(words[idx], words[prevIdx]))
            take = 1 + f(idx + 1, idx, words);

        return max(take, notTake);
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(), comp);

        return f(0, -1, words);
    }
};


// Method 2 : Memoization
// State : dp[idx][prevIdx+1]
// Time : O(N²*L)
// Space : O(N²)
// Restriction : High memory usage

class Solution {
public:
    bool check(string& longer, string& shorter){
        if (longer.size() != shorter.size() + 1) return false;

        int i = 0, j = 0;

        while (i < longer.size()){
            if (j < shorter.size() && longer[i] == shorter[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        return j == shorter.size();
    }

    int f(int idx, int prevIdx, vector<string>& words, vector<vector<int>>& dp){
        if (idx == words.size()){
            return 0;
        }

        if (dp[idx][prevIdx + 1] != -1) return dp[idx][prevIdx + 1];

        int notTake = f(idx + 1, prevIdx, words, dp);

        int take = 0;
        if (prevIdx == -1 || check(words[idx], words[prevIdx]) == true){
            take = 1 + f(idx + 1, idx, words, dp);
        }

        return dp[idx][prevIdx + 1] = max(take, notTake);
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });

        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return f(0, -1, words, dp);
    }
};


// Method 3 : Tabulation
// State : dp[idx][prevIdx+1]
// Time : O(N²*L)
// Space : O(N²)

class Solution {
public:
    bool check(string& longer, string& shorter){
        if (longer.size() != shorter.size() + 1) return false;

        int i = 0, j = 0;

        while (i < longer.size()){
            if (j < shorter.size() && longer[i] == shorter[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        return j == shorter.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int idx = n - 1; idx >= 0; idx--){
            for (int prevIdx = idx - 1; prevIdx >= -1; prevIdx--){
                int notTake = dp[idx + 1][prevIdx + 1];

                int take = 0;
                if (prevIdx == -1 || check(words[idx], words[prevIdx]) == true){
                    take = 1 + dp[idx + 1][idx + 1];
                }

                dp[idx][prevIdx + 1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};


// Method 4 : Classic DP (Recommended)
// State : dp[i] = Longest String Chain ending at i
// Time : O(N²*L)
// Space : O(N)

class Solution {
public:
    static bool comp(string& a, string& b) {
        return a.size() < b.size();
    }

    bool check(string& longer, string& shorter) {

        if (longer.size() != shorter.size() + 1)
            return false;

        int i = 0, j = 0;

        while (i < longer.size()) {

            if (j < shorter.size() &&
                longer[i] == shorter[j]) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }

        return j == shorter.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });

        vector<int> dp(n, 1);

        int ans = 1;

        for (int i = 0; i < n; i++){
            for (int prev = 0; prev < i; prev++){
                if (check(words[i], words[prev])){
                    dp[i] = max(dp[i], dp[prev] + 1);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};


// Method 5 : HashMap DP (Optimal)
// Time : O(N*L²)
// Space : O(N)
// Feature : Best solution for interviews

class Solution {
public:
    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(), [](string& a, string& b) {
                return a.size() < b.size();
            }
        );

        unordered_map<string, int> dp;

        int ans = 1;

        for (string& word : words) {

            dp[word] = 1;

            for (int i = 0; i < word.size(); i++) {

                string prev = word.substr(0, i) + word.substr(i + 1);

                if (dp.count(prev))
                    dp[word] = max(dp[word], dp[prev] + 1);
            }

            ans = max(ans, dp[word]);
        }

        return ans;
    }
};