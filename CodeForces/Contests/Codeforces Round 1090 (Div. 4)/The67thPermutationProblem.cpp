#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> res(3*n);
        int num = n;
        unordered_set<int> used;
        for (int i = 0; i < 3*n; i++) {
            if (i % 3 == 0) {
                res[i] = 3*n - i/3*2 - 1;
                used.insert(res[i]);
            }
            else if (i % 3 == 1){
                res[i] = num--;
            }
            else if (i % 3 == 2){
                res[i] = 3*n - i/3*2;
            }
        }
        for (int i = 0; i < 3*n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}