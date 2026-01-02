class Solution {
public:
    int check(int val, vector<int>& tops, vector<int>& bottoms) {
        int rotateTop = 0;
        int rotateBottom = 0;

        for (int i = 0; i < tops.size(); i++) {
            // If neither side has val, impossible
            if (tops[i] != val && bottoms[i] != val) {
                return -1;
            }
            // Rotate to make top = val
            if (tops[i] != val) rotateTop++;
            // Rotate to make bottom = val
            if (bottoms[i] != val) rotateBottom++;
        }

        return min(rotateTop, rotateBottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = check(tops[0], tops, bottoms);
        if (ans != -1) return ans;
        return check(bottoms[0], tops, bottoms);
    }
};
