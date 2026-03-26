class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int totalTime = 0;
        for(int i = 1; i < n; i++){
            int dx = abs(points[i][0] - points[i-1][0]);
            int dy = abs(points[i][1] - points[i-1][1]);
            totalTime += max(dx, dy); // diagonal moves cover both axes
        }
        return totalTime;
    }
};