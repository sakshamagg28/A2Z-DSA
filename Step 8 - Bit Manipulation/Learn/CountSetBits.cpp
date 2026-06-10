// Best approach
class Solution {
public:
    int countSetBits(int n) {
        // Your code goes here
        int cnt = 0;

        while (n > 0){
            n = n & (n-1);
            cnt++;
        }

        return cnt;
    }
};



// Always log(n) approach
class Solution {
public:
    int countSetBits(int n) {
        // Your code goes here
        int cnt = 0;

        while (n > 0) {
            cnt += (n & 1);
            n >>= 1;
        }

        return cnt;
    }
};