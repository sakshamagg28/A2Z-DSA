class MyQueue {
    stack<int> frontStack, backStack;
public:
    MyQueue() {}  
    
    void push(int x) {
        backStack.push(x);
    }
    
    int pop() {
        if (frontStack.empty()){
            while(backStack.empty() == false){
                frontStack.push(backStack.top());
                backStack.pop();
            }
        }
        if (frontStack.empty()) return -1;

        int popped = frontStack.top();
        frontStack.pop();
        return popped;
    }
    
    int peek() {
        if (frontStack.empty()){
            while(backStack.empty() == false){
                frontStack.push(backStack.top());
                backStack.pop();
            }
        }
        if (frontStack.empty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return frontStack.top();
    }
    
    bool empty() {
        if (frontStack.empty()){
            while(backStack.empty() == false){
                frontStack.push(backStack.top());
                backStack.pop();
            }
        }
        if (frontStack.size() == 0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */