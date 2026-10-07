class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Convert stones into prefix sums
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // If all stones are taken, current player gains
        // the total sum and the game ends.
        int best = stones[n - 1];

        // Work backwards.
        // i starts at n-2 and stops at 1 because
        // at least 2 stones must be taken initially.
        for (int i = n - 2; i >= 1; i--) {
            best = max(
                best,
                stones[i] - best
            );
        }

        return best;
    }
};