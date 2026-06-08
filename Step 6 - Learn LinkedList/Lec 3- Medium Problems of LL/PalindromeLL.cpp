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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast) slow = slow->next;

        ListNode* curr = slow;
        ListNode* prev = nullptr;

        while (curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while (second){
            if (first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};





// Striver's Solution
#include <bits/stdc++.h>
using namespace std;

// Node class represents a node in a linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list

    // Constructor with both data and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to reverse a linked list using the recursive approach
Node* reverseLinkedList(Node* head) {
    // Check if the list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return head;  // No change is needed; return the current head
    }

    // Recursive step: Reverse the remaining part of the list and get the new head
    Node* newHead = reverseLinkedList(head->next);

    // Store the next node in 'front' to reverse the link
    Node* front = head->next;

    // Update the 'next' pointer of 'front' to point to the current head
    front->next = head;

    // Set the 'next' pointer of the current head to null to break the original link
    head->next = NULL;

    // Return the new head obtained from the recursion
    return newHead;
}

// Function to check if the linked list is a palindrome
bool isPalindrome(Node* head) {
    // Check if the linked list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return true;  // It's a palindrome by definition
    }

    // Initialize two pointers, slow and fast, to find the middle of the linked list
    Node* slow = head;
    Node* fast = head;

    // Traverse the linked list to find the middle using slow and fast pointers
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;       // Move slow pointer one step at a time
        fast = fast->next->next; // Move fast pointer two steps at a time
    }

    // Reverse the second half of the linked list starting from the middle
    Node* newHead = reverseLinkedList(slow->next);

    // Pointer to the first half
    Node* first = head;

    // Pointer to the reversed second half
    Node* second = newHead;

    // Compare data values of nodes from both halves
    while (second != NULL) {
        if (first->data != second->data) {
            // If values do not match, the list is not a palindrome
            reverseLinkedList(newHead);  // Reverse the second half back to its original state
            return false;
        }

        first = first->next;  // Move the first pointer
        second = second->next; // Move the second pointer
    }

    // Reverse the second half back to its original state
    reverseLinkedList(newHead);

    // The linked list is a palindrome
    return true;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";  // Print the current node's data
        temp = temp->next;          // Move to the next node
    }
    cout << endl;
}

// Driver function
int main() {
    // Create a linked list with values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
