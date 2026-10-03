class Solution {
public:
    static const int MOD = 1000000007;

    long long power(long long a, long long b) {
        long long result = 1;

        while (b > 0) {
            if (b & 1) {
                result = result * a % MOD;
            }

            a = a * a % MOD;
            b >>= 1;
        }

        return result;
    }

    int makeStringSorted(string s) {
        int n = s.size();

        vector<long long> fact(n + 1, 1);
        vector<long long> invFact(n + 1, 1);

        // Factorials
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        // Inverse factorials
        invFact[n] = power(fact[n], MOD - 2);

        for (int i = n; i >= 1; i--) {
            invFact[i - 1] = invFact[i] * i % MOD;
        }

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        long long answer = 0;

        for (int i = 0; i < n; i++) {

            int current = s[i] - 'a';

            // Try placing every smaller character here
            for (int c = 0; c < current; c++) {

                if (freq[c] == 0)
                    continue;

                // Use one occurrence of this smaller character
                freq[c]--;

                int remaining = n - i - 1;

                // Number of distinct permutations
                long long ways = fact[remaining];

                for (int j = 0; j < 26; j++) {
                    ways = ways * invFact[freq[j]] % MOD;
                }

                answer = (answer + ways) % MOD;

                // Restore character
                freq[c]++;
            }

            // Fix the actual character s[i]
            freq[current]--;
        }

        return answer;
    }
};