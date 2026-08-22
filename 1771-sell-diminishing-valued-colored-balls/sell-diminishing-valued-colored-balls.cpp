class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        const long long MOD = 1e9 + 7;

        sort(inventory.rbegin(), inventory.rend());
        inventory.push_back(0);

        long long ans = 0;
        long long colors = 1;

        for (int i = 0; i < inventory.size() - 1 && orders > 0; i++, colors++) {
            long long current = inventory[i];
            long long next = inventory[i + 1];

            long long balls = (current - next) * colors;

            if (orders >= balls) {
                long long sum = (current + next + 1) * (current - next) / 2;
                ans = (ans + colors * sum) % MOD;
                orders -= balls;
            } else {
                long long fullLevels = orders / colors;
                long long remaining = orders % colors;

                long long lowest = current - fullLevels;

                long long sum = (current + lowest + 1) * fullLevels / 2;
                ans = (ans + colors * sum) % MOD;

                ans = (ans + remaining * lowest) % MOD;

                orders = 0;
            }
        }

        return ans % MOD;
    }
};