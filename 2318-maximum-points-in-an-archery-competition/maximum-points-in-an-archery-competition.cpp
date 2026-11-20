
class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int maxScore = -1;
        vector<int> ans(12, 0);

        for (int mask = 0; mask < (1 << 12); mask++) {
            int arrows = 0;
            int score = 0;
            vector<int> bob(12, 0);

            for (int i = 1; i < 12; i++) {
                if (mask & (1 << i)) {
                    arrows += aliceArrows[i] + 1;
                    score += i;
                    bob[i] = aliceArrows[i] + 1;
                }
            }

            if (arrows > numArrows)
                continue;

            if (score > maxScore) {
                maxScore = score;

                // Assign remaining arrows to section 0
                bob[0] = numArrows - arrows;

                ans = bob;
            }
        }

        return ans;
    }
};
