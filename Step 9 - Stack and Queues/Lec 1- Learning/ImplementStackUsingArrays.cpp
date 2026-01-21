class ArrayStack {
private:
    int* stackArray;
    int capacity;
    int topIndex;
public:
    ArrayStack(int size = 1000) {
        capacity = size;
        stackArray = new int[capacity];
        topIndex = -1;
        
    }

    ~ArrayStack(){
        delete[] stackArray;
    }
    
    void push(int x) {
        if (topIndex >= capacity - 1){
            cout << "Stack Overflow" << endl;
            return;
        }
        stackArray[++topIndex] = x;
    }
    
    int pop() {
        if (topIndex < 0){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stackArray[topIndex--];
    }
    
    int top() {
        if (topIndex < 0){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stackArray[topIndex];
    }
    
    bool isEmpty() {
        if (topIndex < 0){
            return true;
        }
        return false;
    }
};