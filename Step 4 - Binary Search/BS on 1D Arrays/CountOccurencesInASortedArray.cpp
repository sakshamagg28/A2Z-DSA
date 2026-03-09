class Solution {
public:
    int countOccurrences(const vector<int>& arr, int target) {
        // Your code goes here
        int first = firstOccurrence(arr, target);
        int last = lastOccurrence(arr, target);

        return last - first + 1;
    }

    int firstOccurrence(const vector<int>& arr, int target) {
        int low = 0, high = arr.size()-1, mid;
        int first = -1;

        while (high >= low){
            mid = (high - low)/2 + low;

            if (arr[mid] == target){
                first = mid;
                high = mid - 1;
            }
            else if (arr[mid] > target){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return first;
    }

    int lastOccurrence(const vector<int>& arr, int target) {
        int low = 0, high = arr.size()-1, mid;
        int last = -1;

        while (high >= low){
            mid = (high - low)/2 + low;

            if (arr[mid] == target){
                last = mid;
                low = mid + 1;
            }
            else if (arr[mid] > target){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return last;
    }
};