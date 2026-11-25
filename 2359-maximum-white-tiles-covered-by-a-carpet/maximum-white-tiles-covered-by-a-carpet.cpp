class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());

        int n = tiles.size();
        int ans = 0;
        int covered = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {

            int carpetEnd = tiles[i][0] + carpetLen - 1;

            // Count completely covered intervals
            while (j < n && tiles[j][1] <= carpetEnd) {
                covered += tiles[j][1] - tiles[j][0] + 1;
                j++;
            }

            // Count partially covered interval
            int partial = 0;

            if (j < n && tiles[j][0] <= carpetEnd) {
                partial = carpetEnd - tiles[j][0] + 1;
            }

            ans = max(ans, covered + partial);

            if (ans == carpetLen)
                return ans;

            // Remove the current interval from the window
            covered -= tiles[i][1] - tiles[i][0] + 1;
        }

        return ans;
    }
};