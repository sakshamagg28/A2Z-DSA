class ArrayQueue {
private:
    int* queueArray;
    int capacity;
    int frontIndex;
    int backIndex;
public:
    ArrayQueue(int size = 1000) {
        capacity = size;
        queueArray = new int[capacity];
        frontIndex = -1;
        backIndex = -1;
    }

    ~ArrayQueue(){
        delete[] queueArray;
    }
    
    void push(int x) {
        if (backIndex >= capacity - 1){
            cout << "Queue is full" << endl;
            return;
        }
        if (frontIndex == -1) frontIndex = 0;
        queueArray[++backIndex] = x;
    }
    
    int pop() {
        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        int popped = queueArray[frontIndex];
        frontIndex++;

        if (frontIndex > backIndex){
            frontIndex = -1;
            backIndex = -1;
        }
        return popped;
    }
    
    int peek() {
        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return queueArray[frontIndex];
    }
    
    bool isEmpty() {
        if (frontIndex == -1){
            return true;
        }
        return false;
    }
};