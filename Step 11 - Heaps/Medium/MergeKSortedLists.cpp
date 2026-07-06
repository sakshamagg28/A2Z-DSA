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


// Method: Min Heap (Priority Queue)
// Time Complexity: O(N log k)
// Space Complexity: O(k)
// Standard Interview Solution

class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (auto head : lists)
            if (head) pq.push(head);

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next)
                pq.push(node->next);
        }

        return dummy.next;
    }
};



// Method: Divide & Conquer (Pairwise Merge)
// Time Complexity: O(N log k)
// Space Complexity: O(1) (excluding recursion stack)
// Standard Interview Solution

class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (a && b) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        tail->next = a ? a : b;
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int interval = 1;

        while (interval < lists.size()) {
            for (int i = 0; i + interval < lists.size(); i += 2 * interval)
                lists[i] = merge(lists[i], lists[i + interval]);

            interval *= 2;
        }

        return lists[0];
    }
};



// My Solution
// Time Complexity: O(N log N)
// Space Complexity: O(N)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < lists.size(); i++){
            ListNode* temp = lists[i];

            while (temp){
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        if (pq.empty()) return nullptr;
        
        ListNode* head = new ListNode(pq.top());
        pq.pop();
        ListNode* temp = head;
        while (!pq.empty()){
            temp->next = new ListNode(pq.top());
            temp = temp->next;
            pq.pop();
        }

        return head;
    }
};