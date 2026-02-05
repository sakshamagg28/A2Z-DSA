class Solution {
public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // Your code goes here
        vector<int> result(indices.size());
        int count;

        for (int i = 0; i < indices.size(); i++){
            count = 0;
            for (int j = indices[i] + 1; j < arr.size(); j++){
                if (arr[indices[i]] < arr[j]){
                    count++;
                }
            }
            result[i] = count;

        }
        return result;
    }
};