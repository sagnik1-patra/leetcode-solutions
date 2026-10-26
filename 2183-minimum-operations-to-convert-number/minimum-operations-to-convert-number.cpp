class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;
        vector<bool> visited(1001, false);

        q.push(start);
        visited[start] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int x = q.front();
                q.pop();

                if (x == goal) {
                    return steps;
                }

                for (int num : nums) {
                    vector<int> next = {
                        x + num,
                        x - num,
                        x ^ num
                    };

                    for (int y : next) {
                        if (y == goal) {
                            return steps + 1;
                        }

                        if (y >= 0 && y <= 1000 && !visited[y]) {
                            visited[y] = true;
                            q.push(y);
                        }
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};