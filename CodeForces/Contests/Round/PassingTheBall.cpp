#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int count = 0;
        int ans;
        bool ok = false;
        for (int i = 0; i<n; i++){
            char c;
            cin >> c;
            count++;
            if (c == 'L' && !ok){
                ans = count;
                ok = true;
            }
        }
        cout << ans << endl;
    }
    return 0;
}