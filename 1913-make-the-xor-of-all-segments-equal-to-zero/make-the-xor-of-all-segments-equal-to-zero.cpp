class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        const int MAXX = 1 << 10;   // nums[i] < 2^10
        const int INF = 1e9;

        // dp[x] = minimum changes after processed groups,
        // such that XOR of selected group values = x
        vector<int> dp(MAXX, INF);
        dp[0] = 0;

        for (int i = 0; i < k; i++) {

            unordered_map<int, int> freq;
            int size = 0;

            // Elements belonging to group i
            for (int j = i; j < nums.size(); j += k) {
                freq[nums[j]]++;
                size++;
            }

            // Minimum dp value from previous groups
            int best = *min_element(dp.begin(), dp.end());

            // If we choose some arbitrary value for this group,
            // assume every element needs changing.
            vector<int> ndp(MAXX, best + size);

            // Try keeping an existing value in this group
            for (int x = 0; x < MAXX; x++) {
                for (auto &[value, count] : freq) {

                    int previousXor = x ^ value;

                    ndp[x] = min(
                        ndp[x],
                        dp[previousXor] + size - count
                    );
                }
            }

            dp = move(ndp);
        }

        return dp[0];
    }
};