class Solution {
public:
    static const int MOD = 1000000007;
    static const int MAXN = 10020;

    long long modPow(long long base, long long exp) {
        long long result = 1;

        while (exp > 0) {
            if (exp & 1)
                result = result * base % MOD;

            base = base * base % MOD;
            exp >>= 1;
        }

        return result;
    }

    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<long long> fact(MAXN);
        vector<long long> invFact(MAXN);

        // Precompute factorials
        fact[0] = 1;

        for (int i = 1; i < MAXN; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        // Precompute inverse factorials
        invFact[MAXN - 1] =
            modPow(fact[MAXN - 1], MOD - 2);

        for (int i = MAXN - 2; i >= 0; i--) {
            invFact[i] =
                invFact[i + 1] * (i + 1) % MOD;
        }

        auto combination = [&](int n, int r) -> long long {
            if (r < 0 || r > n)
                return 0;

            return fact[n] *
                   invFact[r] % MOD *
                   invFact[n - r] % MOD;
        };

        vector<int> answer;

        for (auto& query : queries) {
            int n = query[0];
            int k = query[1];

            long long ways = 1;

            // Prime factorization of k
            for (int p = 2; p * p <= k; p++) {
                if (k % p == 0) {
                    int exponent = 0;

                    while (k % p == 0) {
                        k /= p;
                        exponent++;
                    }

                    // Distribute exponent identical prime factors
                    // among n positions using stars and bars.
                    ways = ways *
                           combination(n + exponent - 1,
                                       exponent) % MOD;
                }
            }

            // Remaining prime factor
            if (k > 1) {
                // Exponent is 1:
                // C(n, 1) = n
                ways = ways * n % MOD;
            }

            answer.push_back((int)ways);
        }

        return answer;
    }
};