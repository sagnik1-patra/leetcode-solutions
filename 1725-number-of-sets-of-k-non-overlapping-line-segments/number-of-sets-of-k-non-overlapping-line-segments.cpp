class Solution {
public:
    const int MOD = 1e9 + 7;
    
    long long modInverse(long long a) {
        long long res = 1, p = MOD - 2;
        while (p) {
            if (p & 1) res = res * a % MOD;
            a = a * a % MOD;
            p >>= 1;
        }
        return res;
    }
    
    long long nCr(int n, int r) {
        if (r > n) return 0;
        
        long long num = 1, den = 1;
        
        for (int i = 0; i < r; i++) {
            num = num * (n - i) % MOD;
            den = den * (i + 1) % MOD;
        }
        
        return num * modInverse(den) % MOD;
    }
    
    int numberOfSets(int n, int k) {
        return nCr(n + k - 1, 2 * k);
    }
};