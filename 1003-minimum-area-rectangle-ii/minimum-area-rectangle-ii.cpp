class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<long long, vector<pair<int,int>>> mp;

        auto keyHash = [&](long long mx, long long my, long long dist) {
            return (mx << 42) ^ (my << 21) ^ dist;
        };

        // Step 1: group pairs by midpoint and diagonal length
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long mx = points[i][0] + points[j][0]; // doubled midpoint
                long long my = points[i][1] + points[j][1];
                long long dx = points[i][0] - points[j][0];
                long long dy = points[i][1] - points[j][1];
                long long dist = dx * dx + dy * dy;

                long long key = keyHash(mx, my, dist);
                mp[key].push_back({i, j});
            }
        }

        double ans = DBL_MAX;

        // Step 2: compute areas
        for (auto& [_, vec] : mp) {
            int m = vec.size();
            for (int i = 0; i < m; i++) {
                for (int j = i + 1; j < m; j++) {
                    auto [a, c] = vec[i];
                    auto [b, d] = vec[j];

                    long long x1 = points[b][0] - points[a][0];
                    long long y1 = points[b][1] - points[a][1];
                    long long x2 = points[c][0] - points[a][0];
                    long long y2 = points[c][1] - points[a][1];

                    double area = abs((double)(x1 * y2 - y1 * x2));
                    if (area > 0)
                        ans = min(ans, area);
                }
            }
        }

        return ans == DBL_MAX ? 0.0 : ans;
    }
};
