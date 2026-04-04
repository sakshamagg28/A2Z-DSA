#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        a[0] = 1;
        a[1] = 2;
        if (n > 2) a[2] = 6;
        else{
            cout << 1 << " " << 2 << endl;
            continue;
        }
        int num = 3;
        for (int i = 3; i < n; i++) {
            a[i] = num * (num + 2);    
            num += 2;    
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}