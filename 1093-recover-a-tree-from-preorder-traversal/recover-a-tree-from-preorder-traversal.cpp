class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        int i = 0, n = traversal.size();

        while (i < n) {
            int depth = 0;

            // Count dashes to determine depth
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }

            // Parse the node value
            int val = 0;
            while (i < n && isdigit(traversal[i])) {
                val = val * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(val);

            // Ensure stack size matches depth
            while (st.size() > depth) {
                st.pop();
            }

            // Attach node to parent if exists
            if (!st.empty()) {
                if (!st.top()->left)
                    st.top()->left = node;
                else
                    st.top()->right = node;
            }

            st.push(node);
        }

        // Root is at the bottom of the stack
        while (st.size() > 1) st.pop();
        return st.top();
    }
};
