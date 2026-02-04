class MinStack {
    stack<int> st;
    int mini;

public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        if (st.size() == 0) return;
        st.pop();
        
    }
    
    int top() {
        if (st.size() == 0) return -1;
        return st.top();
    }
    
    int getMin() {
        if (st.size() == 0) return -1;
        stack<int> st2 = st;
        mini = INT_MAX;

        for (int i = 0; i < st.size(); i++){
            if (mini > st2.top()) mini = st2.top();
            st2.pop();
        }
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */




// class MinStack {
//     stack<int> st;
//     stack<int> minSt;
// public:
//     MinStack() {
//     }
    
//     void push(int val) {
//         st.push(val);
//         if (minSt.empty() || val <= minSt.top()){
//             minSt.push(val);
//         }
//     }
    
//     void pop() {
//         if (st.size() == 0) return;
//         if (minSt.top() == st.top()){
//             minSt.pop();
//         }
//         st.pop();
        
//     }
    
//     int top() {
//         if (st.size() == 0) return -1;
//         return st.top();
//     }
    
//     int getMin() {
//         if (st.size() == 0) return -1;
//         return minSt.top();
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */