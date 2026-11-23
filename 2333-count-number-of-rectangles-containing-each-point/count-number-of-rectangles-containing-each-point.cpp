class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles,
                                vector<vector<int>>& points) {

        vector<vector<int>> heights(101);

        for (auto &r : rectangles) {
            int l = r[0];
            int h = r[1];

            heights[h].push_back(l);
        }

        for (int i = 1; i <= 100; i++) {
            sort(heights[i].begin(), heights[i].end());
        }

        vector<int> ans;

        for (auto &p : points) {
            int x = p[0];
            int y = p[1];

            int count = 0;

            for (int h = y; h <= 100; h++) {
                auto &v = heights[h];

                int idx = lower_bound(v.begin(), v.end(), x) - v.begin();

                count += v.size() - idx;
            }

            ans.push_back(count);
        }

        return ans;
    }
};