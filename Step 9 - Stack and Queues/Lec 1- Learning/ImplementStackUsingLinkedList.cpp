struct Node {
    int val;
    Node *next;
    Node(int d, Node* n = nullptr){
        val = d;
        next = n;
    }
};


class LinkedListStack {
    Node* head;
    int size;

public:
    LinkedListStack() {
        head = nullptr;
        size = 0;
    }
    
    void push(int x) {
        head = new Node(x, head);
        size++;
    }
    
    int pop() {
        if (size == 0){
            return -1;
        }
        int popped = head->val;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return popped;
    }
    
    int top() {
        if (size == 0){
            return -1;
        }
        return head->val;
    }
    
    bool isEmpty() {
        if (size == 0){
            return true;
        }
        return false;
    }
};