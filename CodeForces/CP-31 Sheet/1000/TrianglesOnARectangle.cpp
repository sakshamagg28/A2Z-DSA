#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        long long w, h;
        cin >> w >> h;
        int k_x0;
        cin >> k_x0;
        vector<long long> x0(k_x0);
        for (int i = 0; i < k_x0; i++){
            cin >> x0[i];
        }
        int k_xh;
        cin >> k_xh;
        vector<long long> xh(k_xh);
        for (int i = 0; i < k_xh; i++){
            cin >> xh[i];
        }
        int k_y0;
        cin >> k_y0;
        vector<long long> y0(k_y0);
        for (int i = 0; i < k_y0; i++){
            cin >> y0[i];
        }
        int k_yw;
        cin >> k_yw;
        vector<long long> yw(k_yw);
        for (int i = 0; i < k_yw; i++){
            cin >> yw[i];
        }

        long long area1 = h * (x0[k_x0-1]-x0[0]);
        long long area2 = w * (y0[k_y0-1]-y0[0]);
        long long area3 = h * (xh[k_xh-1]-xh[0]);
        long long area4 = w * (yw[k_yw-1]-yw[0]);

        long long A = max (max(area1, area2), max(area3, area4));
        
        cout << A << endl;
    }
}