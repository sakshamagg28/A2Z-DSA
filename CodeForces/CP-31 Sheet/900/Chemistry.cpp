#include <bits/stdc++.h>
using namespace std;

void isPalindrome(string s, int n, int k){
    if (n - k == 1){
        cout << "YES" << endl;
        return;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != s[n-i-1]){
            if (s[i] == s[n-i-2]){
                s.erase(n-i-1);
                count++;
            }
            // else if (s[i+1] == s[n-i-1]){
            //     s.erase(i);
            //     count++;
            // }
            else{
                s.erase(i);
                s.erase(n-i-1);
                count += 2;
            }
        }

        if (count >= k){
            cout << "NO" << endl;
        }
    }

    if (count >= k) cout << "NO" << endl;
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        isPalindrome(s, n, k);
    }
    return 0;
}