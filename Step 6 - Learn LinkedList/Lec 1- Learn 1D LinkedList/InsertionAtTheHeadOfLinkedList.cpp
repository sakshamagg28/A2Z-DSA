/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution {
    public:
        ListNode* insertAtHead(ListNode* &head, int X) {
            //your code goes here
            ListNode* newNode = new ListNode(X, head);
            return newNode;
        }

        void printList(ListNode* &head){
            ListNode* temp = head;
            while (temp != nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};