
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long count[1024] = {0};
        count[0] = 1;

        int mask = 0;
        long long ans = 0;

        for (char ch : word) {
            int bit = ch - 'a';

            // Toggle parity of current character
            mask ^= (1 << bit);

            // Case 1: All characters have even frequency
            ans += count[mask];

            // Case 2: Exactly one character has odd frequency
            for (int i = 0; i < 10; i++) {
                ans += count[mask ^ (1 << i)];
            }

            // Store current prefix mask
            count[mask]++;
        }

        return ans;
    }
};
