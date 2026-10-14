
class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[prevRoom[i]].push_back(i);
        }

        // Calculate factorials
        vector<long long> fact(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        // Iterative DFS to avoid stack overflow
        vector<int> order;
        order.reserve(n);
        order.push_back(0);

        for (int i = 0; i < (int)order.size(); i++) {
            int u = order[i];

            for (int v : adj[u]) {
                order.push_back(v);
            }
        }

        // Calculate subtree sizes bottom-up
        vector<int> subtree(n, 1);

        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            subtree[prevRoom[u]] += subtree[u];
        }

        // Number of ways = n! / product(subtree sizes)
        long long denominator = 1;

        for (int size : subtree) {
            denominator = denominator * size % MOD;
        }

        long long ans = fact[n] * modPow(denominator, MOD - 2) % MOD;

        return (int)ans;
    }
};
