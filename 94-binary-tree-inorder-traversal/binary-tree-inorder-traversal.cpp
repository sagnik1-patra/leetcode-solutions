class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode* current = root;

        while (current != nullptr || !stk.empty()) {
            // Reach the leftmost node
            while (current != nullptr) {
                stk.push(current);
                current = current->left;
            }

            // current is null at this point
            current = stk.top();
            stk.pop();
            result.push_back(current->val); // visit the node

            // now visit the right subtree
            current = current->right;
        }

        return result;
    }
};
