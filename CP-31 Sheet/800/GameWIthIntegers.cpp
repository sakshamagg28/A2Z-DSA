#include <bits/stdc++.h>
using namespace std;


void winner(int n){
    if (n % 3 == 0){
        cout << "Second" << endl;
    }
    else {
        cout << "First" << endl;
    }
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        winner(n);
    }
    return 0;
}