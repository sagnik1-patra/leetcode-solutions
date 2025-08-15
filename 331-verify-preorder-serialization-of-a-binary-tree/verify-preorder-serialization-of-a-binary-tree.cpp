class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1; // start with one slot for the root
        int i = 0;
        int n = preorder.size();

        while (i < n) {
            if (--slots < 0) return false; // no slot available

            if (preorder[i] == '#') {
                // null node: consumes 1 slot, adds no new slots
                ++i;
            } else {
                // non-null node: consumes 1 slot, adds 2 slots
                while (i < n && preorder[i] != ',') ++i; // skip number
                slots += 2;
            }

            if (i < n && preorder[i] == ',') ++i; // skip comma
        }
        return slots == 0;
    }
};
