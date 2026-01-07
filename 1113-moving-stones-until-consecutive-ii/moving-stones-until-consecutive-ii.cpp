class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());

        // ---------- MAX MOVES ----------
        int maxMoves = max(
            stones[n-1] - stones[1] - (n - 2),
            stones[n-2] - stones[0] - (n - 2)
        );

        // ---------- MIN MOVES ----------
        int minMoves = n;
        int j = 0;

        for (int i = 0; i < n; i++) {
            while (j < n && stones[j] - stones[i] + 1 <= n) {
                j++;
            }
            int alreadyConsecutive = j - i;

            // Special case
            if (alreadyConsecutive == n - 1 &&
                stones[j - 1] - stones[i] + 1 == n - 1) {
                minMoves = min(minMoves, 2);
            } else {
                minMoves = min(minMoves, n - alreadyConsecutive);
            }
        }

        return {minMoves, maxMoves};
    }
};
