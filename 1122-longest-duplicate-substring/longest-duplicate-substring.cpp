class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        vector<unsigned long long> prefix(n + 1, 0), power(n + 1, 1);
        const unsigned long long base = 1315423911ULL;

        // Precompute prefix hashes and powers
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] * base + s[i];
            power[i + 1] = power[i] * base;
        }

        auto hasDuplicate = [&](int len, int& start) {
            unordered_map<unsigned long long, vector<int>> seen;

            for (int i = 0; i + len <= n; i++) {
                unsigned long long hash =
                    prefix[i + len] - prefix[i] * power[len];

                if (seen.count(hash)) {
                    for (int idx : seen[hash]) {
                        if (s.substr(idx, len) == s.substr(i, len)) {
                            start = i;
                            return true;
                        }
                    }
                }
                seen[hash].push_back(i);
            }
            return false;
        };

        int left = 1, right = n - 1;
        int bestLen = 0, bestStart = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            int start = 0;

            if (hasDuplicate(mid, start)) {
                bestLen = mid;
                bestStart = start;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return bestLen == 0 ? "" : s.substr(bestStart, bestLen);
    }
};
