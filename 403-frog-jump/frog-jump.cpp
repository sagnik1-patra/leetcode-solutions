class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (n < 2) return true;
        if (stones[1] != 1) return false; // first jump must be 1

        unordered_map<int,int> index; index.reserve(n*2);
        for (int i = 0; i < n; ++i) index[stones[i]] = i;

        vector<unordered_set<int>> dp(n);
        dp[0].insert(0);

        for (int i = 0; i < n; ++i) {
            for (int k : dp[i]) {
                for (int d = -1; d <= 1; ++d) {
                    int j = k + d;
                    if (j <= 0) continue;                 // jumps must be positive
                    long long nextPos = 1LL*stones[i] + j;
                    auto it = index.find((int)nextPos);
                    if (it == index.end()) continue;
                    int ni = it->second;
                    if (ni == n - 1) return true;         // reached last stone
                    dp[ni].insert(j);
                }
            }
        }
        return false;
    }
};
