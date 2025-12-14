class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;

        for (int i = 0; i < nums1.size(); i++){
            if (find(arr.begin(), arr.end(), nums1[i]) == arr.end()){
                arr.push_back(nums1[i]);
            }
        }
        for (int i = 0; i < nums2.size(); i++){
            if (find(arr.begin(), arr.end(), nums2[i]) == arr.end()){
                bool inserted = false;
                for (int j = 0; j < arr.size(); j++){
                    if (arr[j] > nums2[i]){
                        arr.insert(arr.begin() + j, nums2[i]);
                        inserted = true;
                        break;
                    }
                }
                if (inserted == false) arr.push_back(nums2[i]);
            }
        }
        return arr;
    }
};