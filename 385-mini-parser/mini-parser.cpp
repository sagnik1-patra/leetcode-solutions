class Solution {
public:
    NestedInteger deserialize(string s) {
        // If it's just an integer, return it directly.
        if (s.empty()) return NestedInteger();
        if (s[0] != '[') return NestedInteger(stoi(s));

        stack<NestedInteger> st;
        int num = 0, sign = 1;
        bool hasNum = false; // whether we're currently parsing a number

        for (int i = 0; i < (int)s.size(); ++i) {
            char c = s[i];
            if (c == '[') {
                st.push(NestedInteger()); // start a new list
            } else if (c == '-') {
                sign = -1;                // negative number
            } else if (isdigit(c)) {
                num = num * 10 + (c - '0');
                hasNum = true;
            } else if (c == ',' || c == ']') {
                // If the previous chars formed a number, add it to current list.
                if (hasNum) {
                    st.top().add(NestedInteger(sign * num));
                    num = 0; sign = 1; hasNum = false;
                }
                // If we close a list, pop and attach to its parent (or return if root).
                if (c == ']') {
                    NestedInteger ni = st.top(); st.pop();
                    if (st.empty()) return ni;   // finished the root list
                    st.top().add(ni);
                }
            }
            // Other characters (commas) are handled in the above branch
        }

        // For completeness (shouldn’t reach here for valid list inputs).
        return NestedInteger();
    }
};
