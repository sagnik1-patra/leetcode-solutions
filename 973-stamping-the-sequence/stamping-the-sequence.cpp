class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size(), m = stamp.size();
        vector<bool> visited(n, false);
        vector<int> res;
        int replaced = 0;

        auto canStamp = [&](int i) {
            bool changed = false;
            for (int j = 0; j < m; j++) {
                if (target[i + j] == '?') continue;
                if (target[i + j] != stamp[j]) return false;
                changed = true;
            }
            return changed;
        };

        auto doStamp = [&](int i) {
            for (int j = 0; j < m; j++) {
                if (target[i + j] != '?') {
                    target[i + j] = '?';
                    replaced++;
                }
            }
        };

        while (replaced < n) {
            bool progress = false;

            for (int i = 0; i <= n - m; i++) {
                if (!visited[i] && canStamp(i)) {
                    visited[i] = true;
                    progress = true;
                    doStamp(i);
                    res.push_back(i);

                    if (replaced == n)
                        break;
                }
            }

            if (!progress)
                return {};
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
