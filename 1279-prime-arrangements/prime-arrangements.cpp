class Solution {
public:
    long long MOD = 1e9 + 7;

    int countPrimes(int n) {
        int count = 0;
        for (int i = 2; i <= n; i++) {
            bool prime = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    prime = false;
                    break;
                }
            }
            if (prime) count++;
        }
        return count;
    }

    long long fact(long long x) {
        long long res = 1;
        for (long long i = 2; i <= x; i++) {
            res = (res * i) % MOD;
        }
        return res;
    }

    int numPrimeArrangements(int n) {
        int p = countPrimes(n);
        int np = n - p;

        long long ans = (fact(p) * fact(np)) % MOD;
        return ans;
    }
};