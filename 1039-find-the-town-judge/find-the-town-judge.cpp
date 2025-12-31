class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n + 1, 0), out(n + 1, 0);

        // Build in-degree and out-degree
        for (auto &t : trust) {
            out[t[0]]++;
            in[t[1]]++;
        }

        // Find the judge
        for (int i = 1; i <= n; i++) {
            if (in[i] == n - 1 && out[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};
