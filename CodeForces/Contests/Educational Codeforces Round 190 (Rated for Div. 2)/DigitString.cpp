#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        // string c = "";
        int count = 0;
        // stack<char> st;
        // for (int i = s.size() - 1; i >= 0; i--) {
        //     if (s[i] == '4'){
        //         count++;
        //     }
        //     else if (s[i] == '2'){
        //         c = "2";
        //         if (!c.empty() && stoi(c) % 4 == 0){
        //             count++;
        //             c = "";
        //         }
        //     }
        //     else{
        //         if (!c.empty()){
        //             c = string(1, s[i]) + c;
        //         }
        //         if (!c.empty() && stoi(c) % 4 == 0){
        //             count++;
        //             c = "";
        //         }
        //     }
        // }

        // for (int i = 0; i < s.size(); i++) {
        //     if (s[i] == '4'){
        //         count++;
        //     }
        //     if (!st.empty()){
        //         if (st.top() == '1' && s[i] == '2'){
        //             count++;
        //         }
        //         if (st.top() == '3' && s[i] == '2'){
        //             count++;
        //         }
        //     }
        //     if (s[i] == '1' || s[i] == '3') {
        //         st.push(s[i]);
        //     }
        // }

        int seen4 = 0, seen2after13 = 0, seen13 = 0, total13 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '4') seen4++;
            if (s[i] == '1' || s[i] == '3') {
                seen13++;
                total13++;
            }
            if (i != 0 && s[i] == '2' && seen13 > 0){
                seen2after13++;
                seen13--;
            }
        }
        if (seen13 >= 0) count = seen4 + seen2after13;
        else count = seen4 + total13;
        cout << count << endl;
    }

    return 0;
}