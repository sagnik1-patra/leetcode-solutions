class Solution {
    static constexpr int MOD = 1337;

    long long modPow(long long base, int exp) {
        base %= MOD;
        long long ans = 1;
        while (exp > 0) {
            if (exp & 1) ans = (ans * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return ans;
    }

public:
    int superPow(int a, vector<int>& b) {
        long long res = 1;
        a %= MOD;  // reduce early
        for (int d : b) {
            // res = res^10 * a^d (mod MOD)
            res = (modPow(res, 10) * modPow(a, d)) % MOD;
        }
        return (int)res;
    }
};
