class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Sort pairs by their second value (right endpoint)
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int curr_end = INT_MIN;
        int count = 0;

        // Greedy selection: pick pairs with smallest possible right value
        for (auto& p : pairs) {
            if (p[0] > curr_end) {
                count++;
                curr_end = p[1];
            }
        }

        return count;
    }
};
