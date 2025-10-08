class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        vector<long long> dist;

        // Compute all 6 pairwise squared distances
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                dist.push_back(squaredDist(points[i], points[j]));
            }
        }

        sort(dist.begin(), dist.end());

        // 4 sides equal and > 0
        if (dist[0] == 0) return false;
        if (!(dist[0] == dist[1] && dist[1] == dist[2] && dist[2] == dist[3])) return false;

        // 2 diagonals equal and twice the side
        if (!(dist[4] == dist[5] && dist[4] == 2 * dist[0])) return false;

        return true;
    }

private:
    long long squaredDist(vector<int>& a, vector<int>& b) {
        long long dx = a[0] - b[0];
        long long dy = a[1] - b[1];
        return dx * dx + dy * dy;
    }
};