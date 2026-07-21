class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size(), m = capacity.size();

        sort(capacity.begin(), capacity.end());

        int total = accumulate(apple.begin(), apple.end(), 0);
        int ans = 0;
        for (int i = m-1; i >= 0; i--){
            total -= capacity[i];
            ans++;

            if (total <= 0){
                break;
            }
        }

        return ans;
    }
};


// Another solution with a same approach
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = accumulate(apple.begin(), apple.end(), 0);

        sort(capacity.begin(), capacity.end(), greater<int>());

        int boxes = 0;

        for (int cap : capacity) {
            total -= cap;
            boxes++;

            if (total <= 0)
                return boxes;
        }

        return boxes;
    }
};