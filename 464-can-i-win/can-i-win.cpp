class Solution {
public:
    bool canIWin(int m, int desiredTotal) {
        if (desiredTotal <= 0) return true;
        int total = m * (m + 1) / 2;
        if (total < desiredTotal) return false;

        unordered_map<int,bool> memo; // key: used_mask*(desiredTotal+1) + remaining (optional),
                                       // or just used_mask with remaining implicit via recursion param capture
        // We'll memo only on used_mask because remaining can be derived from picks,
        // but to keep it simple, memo on used_mask is enough when desiredTotal is fixed for branch.
        // Here, we memo on used_mask and remaining combined as a single key:

        function<bool(int,int)> dfs = [&](int used, int need) -> bool {
            long long key = ((long long)used << 10) | need; // need ≤ 300, fits in 10 bits
            auto it = memo.find((int)key);
            if (it != memo.end()) return it->second;

            for (int x = 1; x <= m; ++x) {
                int bit = 1 << (x - 1);
                if (used & bit) continue;
                if (x >= need || !dfs(used | bit, need - x)) {
                    return memo[(int)key] = true;
                }
            }
            return memo[(int)key] = false;
        };

        return dfs(0, desiredTotal);
    }
};