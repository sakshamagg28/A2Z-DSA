/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* getKth(ListNode* node, int k){
        while(node && --k){
            node = node->next;
        }
        return node;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroup = &dummy;

        while(true){
            ListNode* kth = getKth(prevGroup->next, k);

            if (!kth) break;

            ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;
            ListNode* curr = prevGroup->next;

            while (curr != groupNext){
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            ListNode* oldHead = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = oldHead;
        }

        return dummy.next;
    }
};