#include <bits/stdc++.h>
using namespace std;

void maxValue(vector<int>& a, vector<int>& b, int n){
    a[n-1] = max(a[n-1], b[n-1]);
    for (int i = n-2; i >= 0; i--){
        a[i] = max(a[i+1], max(b[i], a[i]));    
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n, q;
        cin >> n >> q;
        vector<int> a;
        for (int i = 0; i < n; i++){
            int k;
            cin >> k;
            a.push_back(k);
        }
        vector<int> b;
        for (int i = 0; i < n; i++){
            int k;
            cin >> k;
            b.push_back(k);
        }
        maxValue(a,b,n);
        for (int i = 0; i < q; i++){
            int l, r;
            cin >> l >> r;
            long long sum = 0;
            for (int i = l-1; i <= r-1; i++){
                sum += a[i];
            }
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}