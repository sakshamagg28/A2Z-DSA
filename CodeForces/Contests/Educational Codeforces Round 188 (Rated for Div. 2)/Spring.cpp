#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,c,m;
        cin>>a>>b>>c>>m;
        long long alice = 0, bob = 0, carol = 0;

        unordered_map<long long, string> vistors;
        long long num = 1;
        
        while (true){
            if (num*a <= m){
                vistors[num * a] = "A";
                num++;
            }
            else break;
        }
        num = 1;
        while (true){
            if (num*b <= m){
                vistors[num * b] += "B";
                num++;
            }
            else break;
        }
        num = 1;
        while (true){
            if (num*c <= m){
                vistors[num * c] += "C";
                num++;
            }
            else break;
        }
        // while (true){
        //     if (num * a <= m){
        //         vistors[num * a] += "A";
        //     }
        //     if (num * b <= m){
        //         vistors[num * b] += "B";
        //     }
        //     if (num * c <= m){
        //         vistors[num * c] += "C";
        //     }
        //     if (num * a > m && num*b > m && num*c > m) break;
        //     num++;
        // }

        for (auto& p : vistors){
            if (p.second == "A") alice += 6;
            else if (p.second == "B") bob += 6;
            else if (p.second == "C") carol += 6;
            else if (p.second == "AB" || p.second == "BA"){
                alice += 3;
                bob += 3;
            }
            else if (p.second == "AC" || p.second == "CA"){
                alice += 3;
                carol += 3;
            }
            else if (p.second == "BC" || p.second == "CB"){
                bob += 3;
                carol += 3;
            }
            else if (p.second == "ABC"){
                alice += 2;
                bob += 2;
                carol += 2;
            }
        }

        cout << alice << " " << bob << " " << carol << endl;
    }
    return 0;
}