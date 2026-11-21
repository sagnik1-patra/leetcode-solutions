
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> losses;

        for (auto &match : matches) {
            int winner = match[0];
            int loser = match[1];

            // Register winner if not already present
            if (losses.find(winner) == losses.end()) {
                losses[winner] = 0;
            }

            // Increase loser's loss count
            losses[loser]++;
        }

        vector<vector<int>> ans(2);

        for (auto &p : losses) {
            if (p.second == 0) {
                ans[0].push_back(p.first);
            }
            else if (p.second == 1) {
                ans[1].push_back(p.first);
            }
        }

        return ans;
    }
};
