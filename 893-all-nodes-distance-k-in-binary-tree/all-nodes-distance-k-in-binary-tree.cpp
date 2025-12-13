class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    
    void buildParent(TreeNode* node, TreeNode* par) {
        if (!node) return;
        parent[node] = par;
        buildParent(node->left, node);
        buildParent(node->right, node);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParent(root, nullptr);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int dist = 0;

        while (!q.empty()) {
            int size = q.size();

            if (dist == k) {
                vector<int> ans;
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }

            while (size--) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur->left && !visited.count(cur->left)) {
                    visited.insert(cur->left);
                    q.push(cur->left);
                }

                if (cur->right && !visited.count(cur->right)) {
                    visited.insert(cur->right);
                    q.push(cur->right);
                }

                if (parent[cur] && !visited.count(parent[cur])) {
                    visited.insert(parent[cur]);
                    q.push(parent[cur]);
                }
            }
            dist++;
        }

        return {};
    }
};
