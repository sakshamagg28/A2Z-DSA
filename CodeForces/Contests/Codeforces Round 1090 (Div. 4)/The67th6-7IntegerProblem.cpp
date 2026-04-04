#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> a(7);

        int maxVal = 0;
        bool ok = false;
        for (int i = 0; i < 7; i++) {
            cin >> a[i];
            maxVal = max(maxVal, a[i]);
        }
        for (int i = 0; i < 7; i++) {
            if (a[i] == maxVal && !ok) {
                ok = true;
                continue;
            }
            a[i] = -a[i];
        }

        int sum = 0;
        for (int i = 0; i < 7; i++) {
            sum += a[i];
        }
        cout << sum << endl;
    }
    return 0;
}