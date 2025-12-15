class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> obs;
        
        // Store obstacles in hash set
        for (auto& o : obstacles) {
            long long key = (long long)o[0] * 60001 + o[1];
            obs.insert(key);
        }

        // Directions: N, E, S, W
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        int dir = 0; // start facing north
        int x = 0, y = 0;
        int maxDist = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4;          // turn right
            } else if (cmd == -2) {
                dir = (dir + 3) % 4;          // turn left
            } else {
                // move step by step
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    long long key = (long long)nx * 60001 + ny;

                    if (obs.count(key)) break;

                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }

        return maxDist;
    }
};
