// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Codec {
public:
    // Encodes a tree to a single string using preorder with null markers.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializePre(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        istringstream in(data);
        return deserializePre(in);
    }

private:
    void serializePre(TreeNode* node, ostringstream& out) {
        if (!node) { out << "#,"; return; }
        out << node->val << ',';
        serializePre(node->left, out);
        serializePre(node->right, out);
    }

    TreeNode* deserializePre(istringstream& in) {
        string token;
        if (!getline(in, token, ',')) return nullptr;
        if (token == "#" || token.empty()) return nullptr;
        TreeNode* node = new TreeNode(stoi(token));
        node->left = deserializePre(in);
        node->right = deserializePre(in);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
