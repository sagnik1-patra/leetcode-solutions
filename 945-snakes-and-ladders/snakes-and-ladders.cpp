class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int target = n * n;

        auto getPos = [&](int num) {
            int r = n - 1 - (num - 1) / n;
            int c = (num - 1) % n;
            if ((n - r) % 2 == 0) c = n - 1 - c;
            return pair<int,int>{r, c};
        };

        vector<bool> visited(target + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;

        int moves = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int curr = q.front(); q.pop();
                if (curr == target) return moves;

                for (int d = 1; d <= 6 && curr + d <= target; d++) {
                    int next = curr + d;
                    auto [r, c] = getPos(next);
                    if (board[r][c] != -1)
                        next = board[r][c];

                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};
