/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;

        unordered_map <ListNode*, int> nodeMap;
        ListNode* temp = head;
        while (temp != nullptr){
            if (nodeMap.find(temp) != nullptr) return true;
            nodeMap[temp] = 1;

            temp = temp->next;
        }
        return false;
    }
};


// // Tortoise and Hare
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         if (head == nullptr || head->next == nullptr) return false;

//         ListNode* slow = head;
//         ListNode* fast = head;

//         while(fast != nullptr && fast->next != nullptr){
//             slow = slow->next;
//             fast = fast->next->next;

//             if (slow == fast) return true;
//         }
//         return false;
//     }
// };