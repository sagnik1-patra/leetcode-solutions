class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int answer = -1;
        int minDistance = INT_MAX;

        for (int i = 0; i < points.size(); i++) {
            int a = points[i][0];
            int b = points[i][1];

            // Valid if same x-coordinate or same y-coordinate
            if (a == x || b == y) {
                int distance = abs(x - a) + abs(y - b);

                if (distance < minDistance) {
                    minDistance = distance;
                    answer = i;
                }
            }
        }

        return answer;
    }
};