class Solution {
public:
    int reverseNum(int n) {
        int rev = 0;

        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }

        return rev;
    }

    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;

        unordered_map<int, long long> freq;
        long long ans = 0;

        for (int x : nums) {
            int diff = x - reverseNum(x);

            // Every previous number with the same diff
            // forms a nice pair with x
            ans = (ans + freq[diff]) % MOD;

            freq[diff]++;
        }

        return ans;
    }
};