
class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        const int MOD = 1e9 + 7;

        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<int> freq(31, 0);

        for (int num : nums) {
            freq[num]++;
        }

        vector<long long> dp(1 << 10, 0);
        dp[0] = 1;

        for (int num = 2; num <= 30; num++) {
            if (freq[num] == 0)
                continue;

            int mask = 0;
            bool valid = true;

            for (int j = 0; j < 10; j++) {
                int p = primes[j];

                if (num % (p * p) == 0) {
                    valid = false;
                    break;
                }

                if (num % p == 0) {
                    mask |= (1 << j);
                }
            }

            if (!valid)
                continue;

            for (int state = (1 << 10) - 1; state >= 0; state--) {
                if ((state & mask) == 0) {
                    int newState = state | mask;

                    dp[newState] = (
                        dp[newState] +
                        dp[state] * freq[num]
                    ) % MOD;
                }
            }
        }

        long long ans = 0;

        for (int state = 1; state < (1 << 10); state++) {
            ans = (ans + dp[state]) % MOD;
        }

        for (int i = 0; i < freq[1]; i++) {
            ans = (ans * 2) % MOD;
        }

        return ans;
    }
};
