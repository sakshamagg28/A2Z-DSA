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
    ListNode* removeDuplicates(ListNode *head) {
        ListNode* temp = head->next;

        while(temp && temp->prev){
            if (temp->val == temp->prev->val){
                ListNode* nextNode = temp->next;

                temp->prev->next = temp->next;
                
                if (temp->next){
                    temp->next->prev = temp->prev;
                }
                
                delete temp;
                temp = nextNode;
            }
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};