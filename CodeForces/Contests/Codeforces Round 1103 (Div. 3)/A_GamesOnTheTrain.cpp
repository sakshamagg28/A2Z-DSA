#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> h(n);
        int maxi = 0;
        int mini = 10;
        for (int i = 0; i < n; i++){
            cin >> h[i];
            maxi = max(maxi, h[i]);
            mini = min(mini, h[i]);
        }
        
        int ans = maxi - mini + 1;
        cout << ans << endl;
    }
    return 0;
}