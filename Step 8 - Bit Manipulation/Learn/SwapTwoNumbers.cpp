class Solution {
public:
    void swap(int &a, int &b) {
        // Your code goes here
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};