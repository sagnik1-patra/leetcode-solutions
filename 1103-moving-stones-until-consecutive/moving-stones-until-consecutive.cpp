class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());

        int x = v[0], y = v[1], z = v[2];

        int minMoves;
        if (z - x == 2) {
            minMoves = 0;
        } else if (y - x <= 2 || z - y <= 2) {
            minMoves = 1;
        } else {
            minMoves = 2;
        }

        int maxMoves = z - x - 2;

        return {minMoves, maxMoves};
    }
};
