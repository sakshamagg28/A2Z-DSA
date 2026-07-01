// Method 1 : Stack (Recommended)
// Time : O(N)
// Space : O(N)

class Solution {
public:
    bool parseBoolExpr(string expression) {

        stack<char> st;

        for (char ch : expression) {

            if (ch == ',' || ch == '(')
                continue;

            if (ch != ')') {
                st.push(ch);
            }
            else {

                int t = 0, f = 0;

                while (st.top() != '&' &&
                       st.top() != '|' &&
                       st.top() != '!') {

                    if (st.top() == 't') t++;
                    else f++;

                    st.pop();
                }

                char op = st.top();
                st.pop();

                if (op == '&')
                    st.push(f == 0 ? 't' : 'f');

                else if (op == '|')
                    st.push(t > 0 ? 't' : 'f');

                else
                    st.push(f == 1 ? 't' : 'f');
            }
        }

        return st.top() == 't';
    }
};


// Method 2 : Recursive Parser
// Time : O(N)
// Space : O(N)

class Solution {
public:
    bool solve(string& exp, int& i) {

        if (exp[i] == 't') {
            i++;
            return true;
        }

        if (exp[i] == 'f') {
            i++;
            return false;
        }

        char op = exp[i++];
        i++; // Skip '('

        vector<bool> vals;

        while (exp[i] != ')') {

            if (exp[i] == ',') {
                i++;
                continue;
            }

            vals.push_back(solve(exp, i));
        }

        i++; // Skip ')'

        if (op == '!') {
            return !vals[0];
        }

        if (op == '&') {

            for (bool x : vals)
                if (!x)
                    return false;

            return true;
        }

        for (bool x : vals)
            if (x)
                return true;

        return false;
    }

    bool parseBoolExpr(string expression) {

        int i = 0;

        return solve(expression, i);
    }
};