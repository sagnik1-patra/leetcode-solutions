class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<long long> st;
        const long long BASE = 40001; // larger than max y

        // Encode points into a single number
        for (auto& p : points) {
            st.insert((long long)p[0] * BASE + p[1]);
        }

        int ans = INT_MAX;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                // must be diagonal corners
                if (x1 == x2 || y1 == y2) continue;

                // check other two corners
                if (st.count((long long)x1 * BASE + y2) &&
                    st.count((long long)x2 * BASE + y1)) {
                    int area = abs(x1 - x2) * abs(y1 - y2);
                    ans = min(ans, area);
                }
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
