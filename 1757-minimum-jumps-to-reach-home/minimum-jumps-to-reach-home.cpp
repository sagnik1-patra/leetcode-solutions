class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int limit = 6000;

        vector<vector<bool>> visited(limit + 1, vector<bool>(2, false));
        unordered_set<int> blocked(forbidden.begin(), forbidden.end());

        queue<tuple<int, int, int>> q;
        q.push({0, 0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [pos, back, jumps] = q.front();
            q.pop();

            if (pos == x) {
                return jumps;
            }

            int forward = pos + a;

            if (forward <= limit &&
                !blocked.count(forward) &&
                !visited[forward][0]) {

                visited[forward][0] = true;
                q.push({forward, 0, jumps + 1});
            }

            int backward = pos - b;

            if (back == 0 &&
                backward >= 0 &&
                !blocked.count(backward) &&
                !visited[backward][1]) {

                visited[backward][1] = true;
                q.push({backward, 1, jumps + 1});
            }
        }

        return -1;
    }
};