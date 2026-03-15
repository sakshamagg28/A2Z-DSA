#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        unordered_map<int,int> freq;
        bool ok = false;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> a[i][j];
                freq[a[i][j]]++;
                if (freq[a[i][j]] > n*(n-1) && !ok){
                    cout << "NO\n";
                    ok = true;
                }
            }
        } 
        if (!ok) cout << "YES\n";
    }
    return 0;
}