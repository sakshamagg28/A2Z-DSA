class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> freq;
        for (int i = 0; i < hand.size(); i++){
            freq[hand[i]]++;
        }

        for (auto& [num, count] : freq) {
            int currCount = count;

            if (currCount > 0) {
                for (int i = 0; i < groupSize; i++) {
                    if (freq[num + i] < currCount)
                        return false;
                    freq[num + i] -= currCount;
                }
            }
        }

        return true;
    }
};