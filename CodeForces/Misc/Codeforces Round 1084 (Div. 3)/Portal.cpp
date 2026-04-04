#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> p(n);
        for (int i = 0; i < n; i++){
            cin >> p[i];
        }

        bool ok = true;
        while(ok){
            if (x != 0 && y != n && p[x-1] > p[y]){
                swap(p[x-1], p[y]);
            }
            else if (p[x] > p[y-1]){
                swap(p[x], p[y-1]);
            }
            else{
                ok = false;
            }
        }

        while(ok){
            if (p[x] > p[x+1]){
                for (int i = x; i < y-1; i++){
                    swap(p[i], p[i+1]);
                }
            }
            else if ()
        }

        for (int num : p){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}