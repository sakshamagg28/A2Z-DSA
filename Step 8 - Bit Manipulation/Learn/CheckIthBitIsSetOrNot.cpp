class Solution {
public:
    bool checkIthBit(int n, int i) {
        // Your code goes here
        if (((n >> i) & 1) == 1) return true;
        return false;
    }
};