#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        int maxNum = INT_MIN;
        vector<int> index;

        for (int i=0; i<n; i++){
            cin >> a[i];
            if (maxNum <= a[i]){
                maxNum = a[i];
                index.push_back(i);
            }
        }

        cout << index.size() << endl;
    }
    return 0;
}