#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        vector<int> result(n);
        for (int i=0; i<n-1; i++){
            int countG = 0, countS = 0;
            int ans;
            for (int j=i+1; j<n; j++){
                if (a[j] < a[i]) countG++;
                if (a[j] > a[i]) countS++;
                ans = max(countG, countS);
            }
            result[i] = ans;
        }
        
        for (int num : result){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}