class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0.0;
        int n = points.size();

        // Try all triplets of points (brute force, n ≤ 50)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    double area = triangleArea(points[i], points[j], points[k]);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }

private:
    // Calculate area using the Shoelace formula
    double triangleArea(vector<int>& a, vector<int>& b, vector<int>& c) {
        return abs((a[0]*(b[1]-c[1]) +
                    b[0]*(c[1]-a[1]) +
                    c[0]*(a[1]-b[1])) / 2.0);
    }
};