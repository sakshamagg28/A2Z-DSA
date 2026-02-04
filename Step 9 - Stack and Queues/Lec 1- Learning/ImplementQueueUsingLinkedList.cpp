struct Node{
    int val;
    Node* next;
    Node (int d, Node* n = nullptr){
        val = d;
        next = n;
    }
};

class LinkedListQueue {
    Node* head;
    int size;

public:
    LinkedListQueue() {
        head = nullptr;
        size = 0;
    }
    
    void push(int x) {
        if (head == nullptr){
            head = new Node(x, head);
        }
        else {
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = new Node(x, nullptr);
        }
        size++;
    }
    
    int pop() {
        if (head == nullptr) return -1;
        int popped = head->val;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return popped;
    }
    
    int peek() {
        if (head == nullptr) return -1;
        return head->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
};