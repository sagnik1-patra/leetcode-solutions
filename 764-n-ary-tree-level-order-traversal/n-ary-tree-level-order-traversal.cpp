/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _children) : val(_val), children(_children) {}
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            res.emplace_back();
            res.back().reserve(sz);
            for (int i = 0; i < sz; ++i) {
                Node* cur = q.front(); q.pop();
                res.back().push_back(cur->val);
                for (Node* ch : cur->children) {
                    if (ch) q.push(ch);
                }
            }
        }
        return res;
    }
};
