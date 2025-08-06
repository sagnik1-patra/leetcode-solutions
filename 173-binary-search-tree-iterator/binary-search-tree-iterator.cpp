class BSTIterator {
private:
    stack<TreeNode*> st;

    // Helper function to push all leftmost nodes from the current node
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    // Constructor
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    // Returns the next smallest number
    int next() {
        TreeNode* node = st.top(); st.pop();
        if (node->right) {
            pushLeft(node->right);
        }
        return node->val;
    }

    // Returns whether we have a next smallest number
    bool hasNext() {
        return !st.empty();
    }
};
