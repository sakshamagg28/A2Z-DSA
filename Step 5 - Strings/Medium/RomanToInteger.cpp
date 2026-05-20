// class Solution {
// public:
//     int romanToInt(string s) {
//         int ans = 0;
//         int i = 0;
//         while (i < s.size()){
//             if (s[i] == 'M'){
//                 ans += 1000;
//             }
//             else if (s[i] == 'C' && s[i+1] == 'M'){
//                 ans += 900;
//                 i++;
//             }
//             else if (s[i] == 'D'){
//                 ans += 500;
//             }
//             else if (s[i] == 'C' && s[i+1] == 'D'){
//                 ans += 400;
//                 i++;
//             }
//             else if (s[i] == 'C'){
//                 ans += 100;
//             }
//             else if (s[i] == 'X' && s[i+1] == 'C'){
//                 ans += 90;
//                 i++;
//             }
//             else if (s[i] == 'L'){
//                 ans += 50;
//             }
//             else if (s[i] == 'X' && s[i+1] == 'L'){
//                 ans += 40;
//                 i++;
//             }
//             else if (s[i] == 'X'){
//                 ans += 10;
//             }
//             else if (s[i] == 'I' && s[i+1] == 'X'){
//                 ans += 9;
//                 i++;
//             }
//             else if (s[i] == 'V'){
//                 ans += 5;
//             }
//             else if (s[i] == 'I' && s[i+1] == 'V'){
//                 ans += 4;
//                 i++;
//             }
//             else if (s[i] == 'I'){
//                 ans += 1;
//             }
//             i++;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int value(char c) {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        return 1000;
    }

    int romanToInt(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && value(s[i]) < value(s[i + 1])) {
                ans -= value(s[i]);
            } else {
                ans += value(s[i]);
            }
        }

        return ans;
    }
};