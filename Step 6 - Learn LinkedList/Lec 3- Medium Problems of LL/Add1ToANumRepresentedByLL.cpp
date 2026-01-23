/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode *addOne(ListNode *head) {
        head = reverseLL(head);
        ListNode* temp = head;
        if (temp->val != 9){
            temp->val += 1;
            head = reverseLL(head);
            return head;
        }
        else{
            while(temp && temp->val == 9){
                temp->val = 0;
                temp = temp->next;
            }
            if (temp){
                temp->next->val += 1;
            }
            else{
                ListNode* newNode = new ListNode(1);
                newNode->next = head;
                head = newNode;
                return head;
            }
        }
        return head;
    }

    ListNode *reverseLL(ListNode* node){
        ListNode* prev = nullptr;
        ListNode* curr = node;
        while (curr){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
};