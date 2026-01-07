class Solution {
public:
    static constexpr int LIMIT = 20000;
    static constexpr int DIRS[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    bool bfs(vector<int>& start, vector<int>& finish,
             unordered_set<long long>& blockedSet) {

        unordered_set<long long> visited;
        queue<pair<int,int>> q;

        q.push({start[0], start[1]});
        visited.insert(((long long)start[0] << 20) | start[1]);

        while (!q.empty() && visited.size() <= LIMIT) {
            auto [x, y] = q.front();
            q.pop();

            if (x == finish[0] && y == finish[1])
                return true;

            for (auto& d : DIRS) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || ny < 0 || nx >= 1000000 || ny >= 1000000)
                    continue;

                long long key = ((long long)nx << 20) | ny;
                if (blockedSet.count(key) || visited.count(key))
                    continue;

                visited.insert(key);
                q.push({nx, ny});
            }
        }

        // Escaped enclosure
        return visited.size() > LIMIT;
    }

    bool isEscapePossible(vector<vector<int>>& blocked,
                          vector<int>& source,
                          vector<int>& target) {

        unordered_set<long long> blockedSet;
        for (auto& b : blocked) {
            blockedSet.insert(((long long)b[0] << 20) | b[1]);
        }

        return bfs(source, target, blockedSet) &&
               bfs(target, source, blockedSet);
    }
};
