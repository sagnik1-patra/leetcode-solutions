class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap: {distance, {x, y}}
        priority_queue<pair<long long, vector<int>>> pq;

        for (auto &p : points) {
            long long dist = 1LL * p[0] * p[0] + 1LL * p[1] * p[1];
            pq.push({dist, p});

            if (pq.size() > k) {
                pq.pop(); // remove farthest
            }
        }

        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
