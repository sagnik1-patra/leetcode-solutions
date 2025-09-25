class Solution {
public:
    int findRotateSteps(string ring, string key) {
        const int n = (int)ring.size();
        // For each letter, store all indices where it appears on the ring
        array<vector<int>, 26> pos{};
        for (int i = 0; i < n; ++i) {
            pos[ring[i] - 'a'].push_back(i);
        }

        // memo[i][cur] = min steps to spell key[i:] when the ring's 12:00 is at index cur
        vector<vector<int>> memo((int)key.size(), vector<int>(n, -1));

        function<int(int,int)> dfs = [&](int i, int cur) -> int {
            if (i == (int)key.size()) return 0;
            int &res = memo[i][cur];
            if (res != -1) return res;

            res = INT_MAX / 2;
            for (int nxt : pos[key[i] - 'a']) {
                int diff = abs(cur - nxt);
                int rotate = min(diff, n - diff);  // cheaper direction
                // rotate + press(1) + solve rest from position nxt
                res = min(res, rotate + 1 + dfs(i + 1, nxt));
            }
            return res;
        };

        return dfs(0, 0);
    }
};