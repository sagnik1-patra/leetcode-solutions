class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<long long> dp(n);
        dp[0] = 1;                           // 1st super ugly number
        vector<int> idx(k, 0);               // indices for each prime
        vector<long long> val(k);            // next candidate values p[j] * dp[idx[j]]
        for (int j = 0; j < k; ++j) val[j] = primes[j];

        for (int i = 1; i < n; ++i) {
            long long nextVal = *min_element(val.begin(), val.end());
            dp[i] = nextVal;

            // advance all primes that hit nextVal to avoid duplicates
            for (int j = 0; j < k; ++j) {
                if (val[j] == nextVal) {
                    ++idx[j];
                    val[j] = primes[j] * dp[idx[j]];
                }
            }
        }
        return (int)dp[n - 1];
    }
};
