#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i<n; i++){
            cin >> arr[i];
            if (arr[i] == 1) arr[i] = 2;
        }
        for (int i=0; i<n-1; i++){
            while (arr[i+1] % arr[i] == 0){    
                arr[i+1]++;
            }
        }

        for (int num : arr){
            cout << num << " ";
        }
        cout << endl;
    }
}