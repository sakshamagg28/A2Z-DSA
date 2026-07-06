// Method: Greedy (Frequency Counting + Formula)
// Time Complexity: O(N)
// Space Complexity: O(1)
// Standard Interview Solution

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char ch : tasks)
            freq[ch - 'A']++;

        int maxFreq = *max_element(freq.begin(), freq.end());

        int cnt = 0;
        for (int f : freq)
            if (f == maxFreq)
                cnt++;

        return max((int)tasks.size(), (maxFreq - 1) * (n + 1) + cnt);
    }
};




// Method: Max Heap (Greedy Simulation)
// Time Complexity: O(N log 26) ≈ O(N)
// Space Complexity: O(26)

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char ch : tasks)
            freq[ch - 'A']++;

        priority_queue<int> pq;

        for (int f : freq)
            if (f) pq.push(f);

        int time = 0;

        while (!pq.empty()) {
            vector<int> remaining;
            int cycle = n + 1;

            while (cycle-- && !pq.empty()) {
                int f = pq.top();
                pq.pop();

                if (--f > 0)
                    remaining.push_back(f);

                time++;
            }

            for (int f : remaining)
                pq.push(f);

            if (pq.empty())
                break;

            time += cycle + 1;
        }

        return time;
    }
};