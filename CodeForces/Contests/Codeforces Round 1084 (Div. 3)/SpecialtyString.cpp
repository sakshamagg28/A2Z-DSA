#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        for (int i = 0; i < n; i++){
            char c;
            cin >> c;
            s += c;
        }

        bool ok = false;
        if (n%2 != 0){
            cout << "NO\n";
            ok = true;
        }
        else{
            stack<char> st;
            for (int i = 0; i < n; i++){
                if (!st.empty()){
                    if (s[i] == st.top()){
                        st.pop();
                        continue;
                    }
                }
                st.push(s[i]);
            }

            if (st.size() != 0){
                cout << "NO\n";
                ok = true;
            }
            if (!ok) cout << "YES\n";
        }
    }
    return 0;
}