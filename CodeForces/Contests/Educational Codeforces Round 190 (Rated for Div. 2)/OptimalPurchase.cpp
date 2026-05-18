#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;

        long long cost = 0;
        if (a >= b){
            if (n%3 == 0){
                cost = n/3 * b;
            }
            else {
                cost = n/3 * b + b;
            }
        }
        // else if (b < 2*a){
        //     if (n%3 == 0){
        //         cost = n/3 * b;
        //     }
        //     else if (n%3 == 1){
        //         cost = n/3 * b + b;
        //     }
        // }
        // else if (3*a >= b){
        //     cost = n/3 * b + n%3 * a;
        // }
        // else if (3*a < b){
        //     cost = n * a;
        // }

        else if (a < b){
            if (n%3 == 0){
                if (3*a <= b){
                    cost = n * a;
                }
                else if (3*a > b){
                    cost = n/3 * b;
                }
            }
            else if (n%3 == 1){
                if (3*a <= b){
                    cost = n * a;
                }
                else if (3*a > b){
                    cost = n/3 * b + a;

                }
            }
            else if (n%3 == 2){
                if (3*a <= b){
                    cost = n * a;
                }
                else if (2*a > b){
                    cost = n/3 * b + b;
                }
                else if (3*a > b){
                    cost = n/3 * b + 2*a;
                }
            }
        }
        cout << cost << endl;
    }
    return 0;
}