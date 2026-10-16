
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        const int MOD = 1e9 + 7;

        long long end0 = 0;
        long long end1 = 0;
        int hasZero = 0;

        for (char c : binary) {
            if (c == '1') {
                end1 = (end0 + end1 + 1) % MOD;
            } else {
                end0 = (end0 + end1) % MOD;
                hasZero = 1;
            }
        }

        return (end0 + end1 + hasZero) % MOD;
    }
};
