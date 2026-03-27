class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);

        for (int i = 0; i < tasks.size(); i++){
            freq[tasks[i] - 'A']++;
        }

        int maxFreq = 0, countMax = 0;
        for (int f : freq){
            if (f > maxFreq){
                maxFreq = f;
                countMax = 1;
            }
            else if (f == maxFreq){
                countMax++;
            }
        }

        int part = (maxFreq - 1)*(n + 1) + countMax;
        return max((int)tasks.size(), part);
    }
};