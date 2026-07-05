class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> dq; 
        // {x, y - x}

        int ans = INT_MIN;

        for (auto &p : points) {
            int x = p[0];
            int y = p[1];

            // remove points where xj - xi > k
            while (!dq.empty() && x - dq.front().first > k) {
                dq.pop_front();
            }

            // calculate answer using best previous y - x
            if (!dq.empty()) {
                ans = max(ans, x + y + dq.front().second);
            }

            int value = y - x;

            // keep deque decreasing by y - x
            while (!dq.empty() && dq.back().second <= value) {
                dq.pop_back();
            }

            dq.push_back({x, value});
        }

        return ans;
    }
};