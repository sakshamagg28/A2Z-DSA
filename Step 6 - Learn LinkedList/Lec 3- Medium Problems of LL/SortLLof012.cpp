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
    ListNode* sortList(ListNode* &head) {

        ListNode zeroDummy(-1), oneDummy(-1), twoDummy(-1);

        ListNode *zero = &zeroDummy;
        ListNode *one = &oneDummy;
        ListNode *two = &twoDummy;

        ListNode* temp = head;

        while (temp) {
            if (temp->data == 0) {
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->data == 1) {
                one->next = temp;
                one = one->next;
            }
            else {
                two->next = temp;
                two = two->next;
            }

            temp = temp->next;
        }

        zero->next = oneDummy.next ? oneDummy.next : twoDummy.next;
        one->next = twoDummy.next;
        two->next = nullptr;

        return zeroDummy.next;
    }
};