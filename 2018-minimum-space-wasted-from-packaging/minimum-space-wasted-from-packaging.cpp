
class Solution {
public:
    int minWastedSpace(vector<int>& packages,
                       vector<vector<int>>& boxes) {
        const int MOD = 1e9 + 7;

        sort(packages.begin(), packages.end());

        int n = packages.size();

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + packages[i];
        }

        long long ans = LLONG_MAX;

        for (auto& supplier : boxes) {
            sort(supplier.begin(), supplier.end());

            if (supplier.back() < packages.back()) {
                continue;
            }

            long long waste = 0;
            int prev = 0;

            for (int box : supplier) {
                int idx = upper_bound(
                    packages.begin(),
                    packages.end(),
                    box
                ) - packages.begin();

                long long count = idx - prev;

                waste += count * box
                       - (prefix[idx] - prefix[prev]);

                prev = idx;

                if (prev == n) {
                    break;
                }
            }

            ans = min(ans, waste);
        }

        if (ans == LLONG_MAX) {
            return -1;
        }

        return ans % MOD;
    }
};
