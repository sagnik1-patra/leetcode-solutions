class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        unordered_set<string> visited;
        visited.insert("0000");

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();

            if (curr == target) return steps;

            for (int i = 0; i < 4; ++i) {
                string up = curr, down = curr;

                // turn wheel up
                up[i] = (curr[i] == '9') ? '0' : curr[i] + 1;
                // turn wheel down
                down[i] = (curr[i] == '0') ? '9' : curr[i] - 1;

                // push both directions if valid
                if (!dead.count(up) && !visited.count(up)) {
                    visited.insert(up);
                    q.push({up, steps + 1});
                }
                if (!dead.count(down) && !visited.count(down)) {
                    visited.insert(down);
                    q.push({down, steps + 1});
                }
            }
        }

        return -1; // target not reachable
    }
};
