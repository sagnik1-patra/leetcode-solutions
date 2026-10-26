class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> prefix(n + 1, 0);
        vector<int> left(n, -1);
        vector<int> right(n, -1);

        // Step 1: Prefix sum of plates
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (s[i] == '*');
        }

        // Step 2: Nearest candle on the left
        int last = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '|') {
                last = i;
            }
            left[i] = last;
        }

        // Step 3: Nearest candle on the right
        last = -1;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '|') {
                last = i;
            }
            right[i] = last;
        }

        // Step 4: Process queries
        vector<int> ans;

        for (auto& q : queries) {
            int l = right[q[0]];
            int r = left[q[1]];

            if (l != -1 && r != -1 && l < r) {
                ans.push_back(prefix[r] - prefix[l]);
            } else {
                ans.push_back(0);
            }
        }

        return ans;
    }
};