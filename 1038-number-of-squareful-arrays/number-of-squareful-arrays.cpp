class Solution {
public:
    int n;
    vector<int> nums;
    vector<vector<int>> graph;
    vector<vector<int>> memo;

    bool isPerfectSquare(long long x) {
        long long r = sqrt(x);
        return r * r == x;
    }

    int dfs(int mask, int last) {
        if (mask == (1 << n) - 1) {
            return 1; // valid permutation
        }

        if (memo[mask][last] != -1)
            return memo[mask][last];

        int ans = 0;
        for (int next : graph[last]) {
            if (mask & (1 << next)) continue;

            // Skip duplicates
            if (next > 0 && nums[next] == nums[next - 1] &&
                !(mask & (1 << (next - 1))))
                continue;

            ans += dfs(mask | (1 << next), next);
        }

        return memo[mask][last] = ans;
    }

    int numSquarefulPerms(vector<int>& input) {
        nums = input;
        n = nums.size();
        sort(nums.begin(), nums.end());

        // Build graph
        graph.assign(n, {});
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isPerfectSquare((long long)nums[i] + nums[j])) {
                    graph[i].push_back(j);
                }
            }
        }

        memo.assign(1 << n, vector<int>(n, -1));

        int result = 0;
        for (int i = 0; i < n; i++) {
            // Skip duplicates at start
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            result += dfs(1 << i, i);
        }

        return result;
    }
};
