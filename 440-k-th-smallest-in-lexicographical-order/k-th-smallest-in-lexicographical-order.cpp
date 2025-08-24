class Solution {
public:
    int findKthNumber(int n, int k) {
        long long curr = 1;
        k--; // we are already at the 1st number

        while (k > 0) {
            long long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                // skip this whole subtree
                curr += 1;
                k -= steps;
            } else {
                // go down one level
                curr *= 10;
                k -= 1;
            }
        }
        return (int)curr;
    }

private:
    // count numbers in [prefix, nextPrefix) within [1..n]
    long long countSteps(long long n, long long prefix, long long nextPrefix) {
        long long steps = 0;
        while (prefix <= n) {
            steps += std::max(0LL, std::min(n + 1, nextPrefix) - prefix);
            prefix *= 10;
            nextPrefix *= 10;
        }
        return steps;
    }
};
