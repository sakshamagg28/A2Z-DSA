/**
class ListNode
{
 * Definition for doubly-linked list.
 *  public:
 *      int data;
 *      ListNode *prev;
 *      ListNode *next;
 *      ListNode() : data(0), prev(nullptr), next(nullptr) {}
 *      ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
 *      ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};
*/

class Solution {
public:
    ListNode* insertBeforeHead(ListNode* head, int X) {
        // Your code goes here
        ListNode* newNode = new ListNode(X, nullptr, head);
        if (head != nullptr) head->prev = newNode;
        return newNode;
    }
    void printList(ListNode* head){
        ListNode* temp = head;
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};