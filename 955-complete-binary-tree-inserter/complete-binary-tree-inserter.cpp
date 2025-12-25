/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
private:
    TreeNode* root;
    queue<TreeNode*> q;

public:
    CBTInserter(TreeNode* root) {
        this->root = root;

        queue<TreeNode*> bfs;
        bfs.push(root);

        // Level-order traversal to find nodes with missing children
        while (!bfs.empty()) {
            TreeNode* node = bfs.front();
            bfs.pop();

            if (node->left)
                bfs.push(node->left);
            if (node->right)
                bfs.push(node->right);

            if (!(node->left && node->right)) {
                q.push(node);
            }
        }
    }
    
    int insert(int val) {
        TreeNode* parent = q.front();
        TreeNode* newNode = new TreeNode(val);

        if (!parent->left) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
            q.pop();   // parent now has both children
        }

        q.push(newNode);
        return parent->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};
