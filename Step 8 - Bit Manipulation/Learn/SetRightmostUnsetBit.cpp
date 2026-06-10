#include <iostream>
using namespace std;

class Solution{
public:
    int setRightmostUnsetBit(int n){
        return n | (n+1);
    }
};

int main() {
    Solution sol;
    int n = 10; // Example number
    cout << "Original number: " << n << endl;

    // Set the rightmost unset bit
    int result = sol.setRightmostUnsetBit(n);
    
    cout << "Number after setting the rightmost unset bit: " << result << endl;
    
    return 0;
}