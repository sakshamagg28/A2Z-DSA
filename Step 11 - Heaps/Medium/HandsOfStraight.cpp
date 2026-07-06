// Method: Greedy + Ordered Map (Frequency Counting)
// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Standard Interview Solution

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> freq;

        for (int card : hand)
            freq[card]++;

        while (!freq.empty()) {
            int start = freq.begin()->first;

            for (int i = 0; i < groupSize; i++) {
                int card = start + i;

                if (!freq.count(card))
                    return false;

                if (--freq[card] == 0)
                    freq.erase(card);
            }
        }

        return true;
    }
};




// Method: Greedy + Sorting + Hash Map
// Time Complexity: O(N log N)
// Space Complexity: O(N)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        sort(hand.begin(), hand.end());

        unordered_map<int, int> freq;

        for (int card : hand)
            freq[card]++;

        for (int card : hand) {
            if (freq[card] == 0)
                continue;

            for (int i = 0; i < groupSize; i++) {
                if (freq[card + i] == 0)
                    return false;

                freq[card + i]--;
            }
        }

        return true;
    }
};