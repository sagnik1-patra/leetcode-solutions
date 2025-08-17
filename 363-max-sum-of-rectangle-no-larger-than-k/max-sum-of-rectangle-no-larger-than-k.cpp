class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();

        auto bestNoLargerThanK = [&](const vector<int>& a) -> long long {
            // 1D: max subarray sum <= k using prefix sums + ordered set
            long long pref = 0, best = LLONG_MIN;
            set<long long> S; 
            S.insert(0); // prefix before starting (non-empty subarray still enforced by later differences)
            for (int x : a) {
                pref += x;
                // find smallest t in S with t >= pref - k
                auto it = S.lower_bound(pref - k);
                if (it != S.end()) best = max(best, pref - *it);
                S.insert(pref);
            }
            return best;
        };

        long long ans = LLONG_MIN;

        if (n <= m) {
            // Fix left..right columns, compress over rows
            for (int L = 0; L < n; ++L) {
                vector<int> rows(m, 0);
                for (int R = L; R < n; ++R) {
                    for (int i = 0; i < m; ++i) rows[i] += matrix[i][R];
                    ans = max(ans, bestNoLargerThanK(rows));
                    if (ans == k) return (int)ans; // early exit
                }
            }
        } else {
            // Fix top..bottom rows, compress over columns
            for (int T = 0; T < m; ++T) {
                vector<int> cols(n, 0);
                for (int B = T; B < m; ++B) {
                    for (int j = 0; j < n; ++j) cols[j] += matrix[B][j];
                    ans = max(ans, bestNoLargerThanK(cols));
                    if (ans == k) return (int)ans; // early exit
                }
            }
        }

        return (int)ans;
    }
};