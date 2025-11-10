class Solution {
public:
    int racecar(int target) {
        // Each state: (position, speed)
        queue<pair<int,int>> q;
        q.push({0, 1});

        unordered_set<string> visited;
        visited.insert("0_1");

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [pos, speed] = q.front();
                q.pop();

                if (pos == target) return steps;

                // 1️⃣ Accelerate
                int newPos = pos + speed;
                int newSpeed = speed * 2;
                string stateA = to_string(newPos) + "_" + to_string(newSpeed);

                // Stay within reasonable range (-target to 2*target to prune)
                if (abs(newPos) <= 2 * target && !visited.count(stateA)) {
                    visited.insert(stateA);
                    q.push({newPos, newSpeed});
                }

                // 2️⃣ Reverse
                int revSpeed = (speed > 0 ? -1 : 1);
                string stateR = to_string(pos) + "_" + to_string(revSpeed);

                if (!visited.count(stateR)) {
                    visited.insert(stateR);
                    q.push({pos, revSpeed});
                }
            }
            steps++;
        }

        return -1;
    }
};