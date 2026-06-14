#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b, x;
        cin>>a>>b>>x;

        if (a == b){
            cout << 0 << endl;
        }
        else if (abs(a-b) == 1){
            cout << 1 << endl;
        }
        else if (x > a && x > b && abs(a-b) > 2){
            cout << 2 << endl;
        }
        else{
            long long maxi = max(a,b);
            long long mini = min(a,b);

            long long ops = 0;
            long long ans = abs(maxi - mini);
            long long cur = maxi;
            
            while(true){
                ans = min(ans, ops + abs(cur - mini));

                if (cur == 0) break;

                cur /= x;
                ops++;
            }

            cout << ans << endl;
        }
    }
    return 0;
}