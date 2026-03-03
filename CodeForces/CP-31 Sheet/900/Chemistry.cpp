#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        unordered_map<char, int> freq;
        int extraCount = 0;

        for (char c : s){
            freq[c]++;
        }
        for (auto&p : freq){
            if (p.second % 2 != 0){
                extraCount++;
            }
        }
        if (k <= extraCount && extraCount-k <= 1){
            cout << "YES\n";
        }
        else if (k > extraCount){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}