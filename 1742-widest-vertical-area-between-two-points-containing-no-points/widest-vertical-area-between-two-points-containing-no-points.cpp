class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> x;

        // Store all x-coordinates
        for (auto &p : points) {
            x.push_back(p[0]);
        }

        // Sort x-coordinates
        sort(x.begin(), x.end());

        int ans = 0;

        // Maximum gap between consecutive x-coordinates
        for (int i = 1; i < x.size(); i++) {
            ans = max(ans, x[i] - x[i - 1]);
        }

        return ans;
    }
};