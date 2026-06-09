/*
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev; 

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/

class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        // Your code goes here
        unordered_set<int> st;
        vector<vector<int>> pairs;

        while(head){
            if (st.count(target - head->val)){
                pairs.push_back({target - head->val, head->val});
            }
            st.insert(head->val);
            head = head->next;
        }

        sort(pairs.begin(), pairs.end());
        return pairs;
    }
};




// Two Pointer Approach (O(N) time complexity and O(1) space complexity)
class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {

        vector<vector<int>> ans;

        if (head == nullptr)
            return ans;

        ListNode* left = head;
        ListNode* right = head;

        while (right->next)
            right = right->next;

        while (left != right && left->prev != right) {

            int sum = left->val + right->val;

            if (sum == target) {
                ans.push_back({left->val, right->val});
                left = left->next;
                right = right->prev;
            }
            else if (sum < target) {
                left = left->next;
            }
            else {
                right = right->prev;
            }
        }

        return ans;
    }
};