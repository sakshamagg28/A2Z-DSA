class Solution {
public:
    void buildPaths(string word,
                    string beginWord,
                    unordered_map<string, vector<string>>& parents,
                    vector<string>& path,
                    vector<vector<string>>& ans){

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (string parent : parents[word]) {
            path.push_back(parent);
            buildPaths(parent, beginWord, parents, path, ans);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        vector<vector<string>> ans;

        if (!words.count(endWord)) return ans;

        unordered_map<string, vector<string>> parents;
        unordered_set<string> currentLevel{beginWord};
        bool found = false;

        while (!currentLevel.empty() && !found){
            unordered_set<string> nextLevel;

            for (string word : currentLevel){
                words.erase(word);
            }

            for (string word : currentLevel){
                string temp = word;

                for (int i = 0; i < temp.size(); i++){
                    char original = temp[i];
                    for (char ch = 'a'; ch <= 'z'; ch++){
                        if (ch == original) continue;

                        temp[i] = ch;

                        if (words.count(temp)){
                            nextLevel.insert(temp);
                            parents[temp].push_back(word);

                            if (temp == endWord){
                                found = true;
                            }
                        }
                    }
                    temp[i] = original;
                }
            }
            currentLevel = nextLevel;
        }

        if (!found) return ans;
        
        vector<string> path;
        path.push_back(endWord);

        buildPaths(endWord, beginWord, parents, path, ans);

        return ans;
    }
};