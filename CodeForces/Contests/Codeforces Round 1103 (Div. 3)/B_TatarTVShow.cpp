#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s = "";
        int cnt1 = 0;
        for (int i = 0; i < n; i++){
            char c;
            cin >> c;
            s += c;
            if (c == '1') cnt1++;
        }

        if (cnt1 % 2 != 0){
            cout << "NO" << endl;
        }
        else {
            for (int i = 0; i < n-k; i++){
                if (s[i] == '1'){
                    if (s[i+k] == '1'){
                        cnt1 -= 2;
                        s[i] = '0';
                        s[i+k] = '0';
                    }
                    else{
                        s[i] = '0';
                        s[i+k] = '1';
                    }
                }
            }
            if (cnt1 == 0){
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}