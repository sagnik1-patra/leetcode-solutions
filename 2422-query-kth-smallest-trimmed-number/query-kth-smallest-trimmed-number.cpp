class Solution {
public:
    vector<int> smallestTrimmedNumbers(
        vector<string>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        int len = nums[0].size();

        vector<vector<int>> order(len + 1, vector<int>(n));

        // Initialize original indices
        for (int i = 0; i < n; i++) {
            order[0][i] = i;
        }

        for (int trim = 1; trim <= len; trim++) {

            vector<int> bucket[10];

            int pos = len - trim;

            // Place indices into buckets
            for (int idx : order[trim - 1]) {
                int digit = nums[idx][pos] - '0';

                bucket[digit].push_back(idx);
            }

            // Collect indices in sorted order
            int j = 0;

            for (int d = 0; d < 10; d++) {
                for (int idx : bucket[d]) {
                    order[trim][j++] = idx;
                }
            }
        }

        vector<int> ans;

        for (auto q : queries) {
            int k = q[0];
            int trim = q[1];

            ans.push_back(order[trim][k - 1]);
        }

        return ans;
    }
};