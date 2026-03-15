#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, p, m;
        cin>>n>>k>>p>>m;
        vector<int> a(n);
        for (int i = 0; i< n; i++){
            cin >> a[i];
        }

        if (k == n){
            cout << m/a[p-1] << endl;
        }
        else{
            int sum = 0;
            int ans = 0;
            int win_value = a[p-1];
            int win_pos = p;
            while (sum < m){
                if (k < win_pos){
                    int mini = INT_MAX;
                    for (int i = 0; i < k; i++){
                        mini = min (mini, a[i]);
                    }
                    if (sum + mini > m) break;
                    sum += mini;
                    auto it = find(a.begin(), a.begin() + k, mini);
                    a.erase(it);
                    a.push_back(mini);
                    win_pos--;
                }
                else{
                    if (sum + win_value > m) break;
                    sum += win_value;
                    ans++;
                    auto it = find(a.begin(), a.begin()+k, win_value);
                    a.erase(it);
                    a.push_back(win_value);
                    win_pos = n;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}