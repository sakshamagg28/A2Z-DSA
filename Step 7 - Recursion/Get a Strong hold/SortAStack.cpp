class Solution {
public:
    void sortStack(stack<int>& st) {
        // Your code goes here
        if (st.empty()) return;

        int top = st.top();
        st.pop();
        sortStack(st);

        insertSorted(st, top);
    }

    void insertSorted(stack<int>& st, int top){
        if (st.empty() || st.top() <= top){
            st.push(top);
            return;
        }

        int temp = st.top();
        st.pop();

        insertSorted(st, top);

        st.push(temp);
    }
};