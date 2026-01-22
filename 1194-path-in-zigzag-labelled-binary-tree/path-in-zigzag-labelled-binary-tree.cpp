class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> path;

        // Step 1: find the level of the label
        int level = 0;
        int temp = label;
        while (temp > 0) {
            level++;
            temp >>= 1;
        }

        // Step 2: build path from label to root
        while (label > 0) {
            path.push_back(label);

            int start = 1 << (level - 1);
            int end = (1 << level) - 1;

            // Convert to normal label, find parent, then convert back
            label = (start + end - label) / 2;
            level--;
        }

        reverse(path.begin(), path.end());
        return path;
    }
};
