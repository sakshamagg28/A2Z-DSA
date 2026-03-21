#include <iostream>
#include <vector>
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
        }
        cout << c << endl;
    }
    return 0;
}