class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        // Compute your distance (Manhattan distance)
        int myDist = abs(target[0]) + abs(target[1]);

        // If any ghost can reach target in less or equal steps, you lose
        for (auto& g : ghosts) {
            int ghostDist = abs(g[0] - target[0]) + abs(g[1] - target[1]);
            if (ghostDist <= myDist)
                return false;
        }
        return true;
    }
};