class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> heights(n);
        int maxHeight = 0;
        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            int left = positions[i][0];
            int size = positions[i][1];
            int right = left + size;
            int currHeight = 0;

            // Check overlap with all previous squares
            for (int j = 0; j < i; ++j) {
                int prevLeft = positions[j][0];
                int prevRight = positions[j][0] + positions[j][1];

                // If they overlap, square i can land on square j
                if (right > prevLeft && left < prevRight) {
                    currHeight = max(currHeight, heights[j]);
                }
            }

            heights[i] = currHeight + size; // new top height
            maxHeight = max(maxHeight, heights[i]);
            ans.push_back(maxHeight);
        }

        return ans;
    }
};
