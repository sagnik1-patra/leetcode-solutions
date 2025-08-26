/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
 * };
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string out;
        serializePre(root, out);
        if (!out.empty()) out.pop_back(); // remove trailing space
        return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<int> vals;
        vals.reserve(data.size() / 2 + 1);
        parseVals(data, vals);

        int idx = 0;
        return build(vals, idx, LONG_MIN, LONG_MAX);
    }

private:
    void serializePre(TreeNode* node, string& out) {
        if (!node) return;
        out.append(to_string(node->val));
        out.push_back(' ');
        serializePre(node->left, out);
        serializePre(node->right, out);
    }

    void parseVals(const string& s, vector<int>& vals) {
        int i = 0, n = s.size();
        while (i < n) {
            bool neg = false;
            if (s[i] == '-') { neg = true; ++i; }
            long long v = 0;
            while (i < n && isdigit(s[i])) { v = v * 10 + (s[i]-'0'); ++i; }
            vals.push_back(neg ? -(int)v : (int)v);
            while (i < n && s[i] == ' ') ++i; // skip spaces
        }
    }

    TreeNode* build(const vector<int>& vals, int& idx, long long lo, long long hi) {
        if (idx >= (int)vals.size()) return nullptr;
        int v = vals[idx];
        if (v <= lo || v >= hi) return nullptr;
        ++idx;
        TreeNode* node = new TreeNode(v);
        node->left  = build(vals, idx, lo, v);
        node->right = build(vals, idx, v, hi);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
