class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> ones1, ones2;

        // Record positions of 1s in both images
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j]) ones1.push_back({i, j});
                if (img2[i][j]) ones2.push_back({i, j});
            }
        }

        unordered_map<string, int> shiftCount;
        int maxOverlap = 0;

        // Compare all pairs of 1s between img1 and img2
        for (auto &[x1, y1] : ones1) {
            for (auto &[x2, y2] : ones2) {
                int dx = x2 - x1, dy = y2 - y1;
                string key = to_string(dx) + "," + to_string(dy);
                maxOverlap = max(maxOverlap, ++shiftCount[key]);
            }
        }

        return maxOverlap;
    }
};