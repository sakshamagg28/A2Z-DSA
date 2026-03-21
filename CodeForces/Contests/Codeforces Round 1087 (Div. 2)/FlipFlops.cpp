#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,c,k;
        cin >>n>>c>>k;
        vector<long long> a(n);
        for (int i=0; i<n; i++){
            cin >> a[i];
        }
        sort (a.begin(), a.end());
        for (int i = 0; i<n; i++){
            if (a[i] <= c) {
                if (k > 0){
                    if (c - a[i] >= k) {
                        a[i] += k;
                        k = 0;
                    }
                    else {
                        k = k - (c - a[i]);
                        a[i] = c;
                    }
                }
                c += a[i];
            }
            else break;
        }
        cout << c << endl;
    }
    return 0;
}