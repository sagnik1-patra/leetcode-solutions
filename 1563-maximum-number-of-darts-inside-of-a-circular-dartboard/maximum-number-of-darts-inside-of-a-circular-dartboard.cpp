class Solution {
public:
    double dist(pair<int,int>& a, pair<int,int>& b) {
        return hypot(a.first - b.first, a.second - b.second);
    }
    
    int countPoints(vector<pair<int,int>>& points, double cx, double cy, int r) {
        int count = 0;
        for (auto &p : points) {
            if (hypot(p.first - cx, p.second - cy) <= r + 1e-6) {
                count++;
            }
        }
        return count;
    }
    
    int numPoints(vector<vector<int>>& darts, int r) {
        int n = darts.size();
        vector<pair<int,int>> points;
        
        for (auto &d : darts) {
            points.push_back({d[0], d[1]});
        }
        
        int result = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                auto &A = points[i];
                auto &B = points[j];
                
                double d = dist(A, B);
                
                if (d > 2.0 * r) continue;
                
                double mx = (A.first + B.first) / 2.0;
                double my = (A.second + B.second) / 2.0;
                
                double h = sqrt(r * r - (d / 2) * (d / 2));
                
                double dx = (B.second - A.second) / d;
                double dy = (A.first - B.first) / d;
                
                // two centers
                double cx1 = mx + h * dx;
                double cy1 = my + h * dy;
                
                double cx2 = mx - h * dx;
                double cy2 = my - h * dy;
                
                result = max(result, countPoints(points, cx1, cy1, r));
                result = max(result, countPoints(points, cx2, cy2, r));
            }
        }
        
        return result;
    }
};