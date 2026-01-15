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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        int count = 0, mid;
        ListNode* temp = head;
        while (temp != nullptr){
            count++;
            temp = temp->next;
        }
        // if (count%2 == 0) mid = count/2 + 1;
        // else mid = count/2 + 1;
        mid = count/2 + 1;

        int count2 = 0;
        ListNode* temp2 = head;
        while (temp2 != nullptr){
            count2++;
            if (count2 == mid) return temp2;
            temp2 = temp2->next;
        }
        return nullptr;


        // ** Tortoise and Hare algorithm

        // if (head == nullptr || head->next == nullptr) return head;
        // ListNode* mid = head;
        // ListNode* end = head;
        // while (end != nullptr && end->next != nullptr){
        //     mid = mid->next;
        //     end = end->next->next;
        // }
        // return mid;
    }
};