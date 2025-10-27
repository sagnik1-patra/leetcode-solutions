class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> st;
        st.push({});
        int n = formula.size();

        for (int i = 0; i < n; ) {
            char c = formula[i];
            
            // Case 1: Opening bracket '('
            if (c == '(') {
                st.push({});
                ++i;
            } 
            // Case 2: Closing bracket ')'
            else if (c == ')') {
                ++i;
                int val = 0;
                while (i < n && isdigit(formula[i])) {
                    val = val * 10 + (formula[i] - '0');
                    ++i;
                }
                val = (val == 0 ? 1 : val);
                auto top = st.top();
                st.pop();

                for (auto& [atom, cnt] : top)
                    st.top()[atom] += cnt * val;
            } 
            // Case 3: Atom name
            else {
                string name;
                name += formula[i++]; // uppercase
                while (i < n && islower(formula[i]))
                    name += formula[i++];

                int val = 0;
                while (i < n && isdigit(formula[i])) {
                    val = val * 10 + (formula[i] - '0');
                    ++i;
                }
                val = (val == 0 ? 1 : val);
                st.top()[name] += val;
            }
        }

        // Final flattened map
        auto& resultMap = st.top();
        string result;
        for (auto& [atom, count] : resultMap)
            result += atom + (count > 1 ? to_string(count) : "");
        return result;
    }
};
