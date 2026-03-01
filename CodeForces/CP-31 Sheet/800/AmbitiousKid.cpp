#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> arr(N);
    int minAbs = INT_MAX;
    for (int i=0; i<N; i++){
        cin >> arr[i];
        if (abs(arr[i]) < minAbs) minAbs = abs(arr[i]);
    }
    cout << minAbs << endl;
    return 0;
}