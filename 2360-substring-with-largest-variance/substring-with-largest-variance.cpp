class Solution {
public:
    int largestVariance(string s) {
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int ans = 0;

        for (char major = 'a'; major <= 'z'; major++) {
            for (char minor = 'a'; minor <= 'z'; minor++) {

                if (major == minor ||
                    freq[major - 'a'] == 0 ||
                    freq[minor - 'a'] == 0) {
                    continue;
                }

                int majorCount = 0;
                int minorCount = 0;
                int remainingMinor = freq[minor - 'a'];

                for (char ch : s) {

                    if (ch == major) {
                        majorCount++;
                    }

                    if (ch == minor) {
                        minorCount++;
                        remainingMinor--;
                    }

                    // Both characters must be present
                    if (minorCount > 0) {
                        ans = max(ans, majorCount - minorCount);
                    }

                    // Modified Kadane's reset condition
                    if (majorCount < minorCount &&
                        remainingMinor > 0) {

                        majorCount = 0;
                        minorCount = 0;
                    }
                }
            }
        }

        return ans;
    }
};