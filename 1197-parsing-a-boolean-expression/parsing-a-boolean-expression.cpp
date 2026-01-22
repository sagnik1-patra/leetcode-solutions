class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char ch : expression) {
            if (ch == ',') continue;

            if (ch != ')') {
                st.push(ch);
            } else {
                // Collect operands
                bool hasTrue = false, hasFalse = false;

                while (st.top() != '(') {
                    char val = st.top();
                    st.pop();
                    if (val == 't') hasTrue = true;
                    if (val == 'f') hasFalse = true;
                }

                st.pop();               // remove '('
                char op = st.top();     // operator
                st.pop();

                // Evaluate
                if (op == '!') {
                    st.push(hasTrue ? 'f' : 't');
                } else if (op == '&') {
                    st.push(hasFalse ? 'f' : 't');
                } else { // '|'
                    st.push(hasTrue ? 't' : 'f');
                }
            }
        }

        return st.top() == 't';
    }
};
