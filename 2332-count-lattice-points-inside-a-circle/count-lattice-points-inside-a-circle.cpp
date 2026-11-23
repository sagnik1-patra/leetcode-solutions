class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int, int>> st;

        for (auto &c : circles) {
            int x = c[0];
            int y = c[1];
            int r = c[2];

            for (int i = x - r; i <= x + r; i++) {
                for (int j = y - r; j <= y + r; j++) {

                    if ((i - x) * (i - x) +
                        (j - y) * (j - y) <= r * r) {

                        st.insert({i, j});
                    }
                }
            }
        }

        return st.size();
    }
};