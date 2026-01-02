class Solution {
public:
    vector<int> gridIllumination(
        int n,
        vector<vector<int>>& lamps,
        vector<vector<int>>& queries
    ) {
        unordered_map<long long, int> row, col, diag, anti;
        unordered_set<long long> active;

        auto key = [&](int r, int c) {
            return (long long)r * n + c;
        };

        // Initialize lamps
        for (auto &l : lamps) {
            int r = l[0], c = l[1];
            long long k = key(r, c);
            if (active.insert(k).second) {
                row[r]++;
                col[c]++;
                diag[r - c]++;
                anti[r + c]++;
            }
        }

        vector<int> ans;
        vector<pair<int,int>> dirs = {
            {0,0},{1,0},{-1,0},{0,1},{0,-1},
            {1,1},{1,-1},{-1,1},{-1,-1}
        };

        // Process queries
        for (auto &q : queries) {
            int r = q[0], c = q[1];

            // Check illumination
            if (row[r] > 0 || col[c] > 0 ||
                diag[r - c] > 0 || anti[r + c] > 0)
                ans.push_back(1);
            else
                ans.push_back(0);

            // Turn off lamps in 3x3 area
            for (auto &d : dirs) {
                int nr = r + d.first;
                int nc = c + d.second;
                if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;

                long long k = key(nr, nc);
                if (active.count(k)) {
                    active.erase(k);
                    row[nr]--;
                    col[nc]--;
                    diag[nr - nc]--;
                    anti[nr + nc]--;
                }
            }
        }

        return ans;
    }
};
