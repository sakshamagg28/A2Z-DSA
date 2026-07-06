// Method: Greedy + Min Heap (Huffman Coding)
// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Standard Interview Solution

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int stick : sticks)
            pq.push(stick);

        int cost = 0;

        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();

            int second = pq.top();
            pq.pop();

            int sum = first + second;
            cost += sum;

            pq.push(sum);
        }

        return cost;
    }
};