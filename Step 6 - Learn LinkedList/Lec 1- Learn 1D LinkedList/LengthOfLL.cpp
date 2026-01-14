/*Defination of ListNode
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/

class Solution {
public:
    int getLength(ListNode* head) {
        int length = 0;
        while (head != nullptr){
            length++;
            head = head->next;
        }
        return length;
    }
};
