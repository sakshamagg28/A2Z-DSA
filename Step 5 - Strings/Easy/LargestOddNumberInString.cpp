class Solution {
public:
    string largestOddNumber(string num) {
        int index = -1;
        for (int i = num.size()-1; i >= 0; i--){
            if (num[i] % 2 != 0){
                index = i;
                break;
            }
        }
        if (index == -1) return "";

        num.erase(num.begin() + index + 1, num.end());
        return num;
    }
};