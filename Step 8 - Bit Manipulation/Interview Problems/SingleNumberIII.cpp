class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;

        for (int num : nums){
            xr ^= num;
        }

        unsigned int ux = xr;
        unsigned int diff = ux & -ux;

        int a = 0, b = 0;

        for (int num : nums){
            if ((unsigned int)num & diff){
                a ^= num;
            }
            else {
                b ^= num;
            }
        }

        if (a > b) swap(a, b);

        return {a, b};
    }
};