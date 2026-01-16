class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> freq;

        for (auto& row : matrix) {
            string pattern;
            int flip = row[0]; // normalize based on first value

            for (int val : row) {
                pattern.push_back((val ^ flip) + '0');
            }

            freq[pattern]++;
        }

        int ans = 0;
        for (auto& p : freq) {
            ans = max(ans, p.second);
        }

        return ans;
    }
};
