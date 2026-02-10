class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int result = 0;
        int left = 0, right = n-1;
        int maxLeft = 0, maxRight = 0;

        while(left <= right){
            if (height[left] <= height[right]){
                if (height[left] >= maxLeft){
                    maxLeft = height[left];
                }
                else{
                    result += maxLeft - height[left];
                }
                left++;
            }
            else{
                if (height[right] >= maxRight){
                    maxRight = height[right];
                }
                else{
                    result += maxRight - height[right];
                }
                right--;
            }
        }
        return result;
    }
};