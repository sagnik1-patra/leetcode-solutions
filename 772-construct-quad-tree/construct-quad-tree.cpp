/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() : val(false), isLeaf(false), topLeft(nullptr), topRight(nullptr),
             bottomLeft(nullptr), bottomRight(nullptr) {}

    Node(bool _val, bool _isLeaf) : val(_val), isLeaf(_isLeaf),
             topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
         Node* _bottomLeft, Node* _bottomRight)
        : val(_val), isLeaf(_isLeaf), topLeft(_topLeft), topRight(_topRight),
          bottomLeft(_bottomLeft), bottomRight(_bottomRight) {}
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        return build(grid, 0, 0, n);
    }

private:
    // Build quad-tree for sub-square with top-left at (r,c) and size len
    Node* build(const vector<vector<int>>& g, int r, int c, int len) {
        if (len == 1) {
            return new Node(g[r][c] == 1, true);
        }

        if (isUniform(g, r, c, len)) {
            return new Node(g[r][c] == 1, true);
        }

        int half = len / 2;
        Node* tl = build(g, r, c, half);
        Node* tr = build(g, r, c + half, half);
        Node* bl = build(g, r + half, c, half);
        Node* br = build(g, r + half, c + half, half);

        // The val field for non-leaf can be arbitrary (true/false); use true
        return new Node(true, false, tl, tr, bl, br);
    }

    bool isUniform(const vector<vector<int>>& g, int r, int c, int len) {
        int v = g[r][c];
        for (int i = r; i < r + len; ++i)
            for (int j = c; j < c + len; ++j)
                if (g[i][j] != v) return false;
        return true;
    }
};
