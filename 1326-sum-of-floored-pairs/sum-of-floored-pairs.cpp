class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        const int MOD = 1000000007;

        int maxVal = *max_element(nums.begin(), nums.end());

        // Frequency of each value
        vector<long long> freq(maxVal + 1, 0);

        for (int x : nums) {
            freq[x]++;
        }

        // Prefix frequency
        vector<long long> prefix(maxVal + 1, 0);

        for (int i = 1; i <= maxVal; i++) {
            prefix[i] = prefix[i - 1] + freq[i];
        }

        long long answer = 0;

        // Treat d as the denominator
        for (int d = 1; d <= maxVal; d++) {

            if (freq[d] == 0)
                continue;

            // Values in [k*d, (k+1)*d - 1]
            // contribute floor(x/d) = k
            for (int left = d, k = 1;
                 left <= maxVal;
                 left += d, k++) {

                int right = min(maxVal, left + d - 1);

                long long count = prefix[right] - prefix[left - 1];

                long long contribution =
                    (freq[d] * count) % MOD;

                contribution =
                    (contribution * k) % MOD;

                answer =
                    (answer + contribution) % MOD;
            }
        }

        return answer;
    }
};