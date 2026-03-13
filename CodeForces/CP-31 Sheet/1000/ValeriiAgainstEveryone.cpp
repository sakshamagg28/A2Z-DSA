#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> b(n);
        unordered_set<long long> seen;
        bool ok = false;
        for (int i = 0; i < n; i++){
            cin >> b[i];
        }
        for (int i = 0; i < n; i++){
            if (seen.find(b[i]) != seen.end()){
                cout << "YES\n";
                ok = true;
                break;
            }
            seen.insert(b[i]);
        }
        if (!ok){
            cout << "NO\n";
        }
    }
    return 0;
}