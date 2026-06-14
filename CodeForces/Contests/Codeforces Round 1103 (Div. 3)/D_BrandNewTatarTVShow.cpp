#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        unordered_map<int,int> freq;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            freq[a[i]]++;
        }

        sort(a.begin(), a.end());
        bool ok = false;

        int maxNumFreq = 1;
        for (int i = n-2; i >= 0; i--){
            if (a[i] == a[i+1]) maxNumFreq++;
            else break;
        }

        if (maxNumFreq % 2 == 0){
            ok = true;
            cout << "YES" << endl;
        }

        if (!ok){
            for (int i = 0; i < n-1; i++){
                if (a[i+1] - a[i] > k){
                    if (freq[a[i]] % 2 == 0){
                        ok = true;
                        cout << "YES" << endl;
                        break;
                    }
                }
                else if (a[i] != a[i+1] && a[i+1] - a[i] <= k){
                    if (freq[a[i+1]] % 2 != 0){
                        ok = true;
                        cout << "YES" << endl;
                        break;
                    }
                }
            }
        }
        if(!ok) {
            cout << "NO" << endl;
        }

    }
    return 0;
}