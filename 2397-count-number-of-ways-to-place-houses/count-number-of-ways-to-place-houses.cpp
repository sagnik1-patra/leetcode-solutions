class Solution {
public:
    int countHousePlacements(int n) {

        const int MOD = 1e9 + 7;

        long long prev2 = 1;
        long long prev1 = 2;

        for (int i = 2; i <= n; i++) {

            long long curr = (prev1 + prev2) % MOD;

            prev2 = prev1;
            prev1 = curr;
        }

        return (prev1 * prev1) % MOD;
    }
};