/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution {
public:
    ListNode * deleteAllOccurrences(ListNode* head, int target) {
        ListNode* temp = head;

        while (temp){
            if (temp->val == target){
                ListNode* nextNode = temp->next;

                if (temp->prev){
                    temp->prev->next = temp->next;
                }
                else{
                    head = temp->next;
                }

                if (temp->next){
                    temp->next->prev = temp->prev;
                }

                delete temp;
                temp = nextNode;
            }

            else temp = temp->next;
        }

        return head;
    }
};