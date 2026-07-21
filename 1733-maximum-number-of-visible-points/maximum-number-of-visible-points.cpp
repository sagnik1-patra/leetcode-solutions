class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles;
        int same = 0;
        
        int x0 = location[0], y0 = location[1];
        
        for (auto &p : points) {
            int x = p[0], y = p[1];
            
            if (x == x0 && y == y0) {
                same++;
            } else {
                double ang = atan2(y - y0, x - x0) * 180 / M_PI;
                angles.push_back(ang);
            }
        }
        
        sort(angles.begin(), angles.end());
        
        int n = angles.size();
        
        // duplicate for circular handling
        for (int i = 0; i < n; i++) {
            angles.push_back(angles[i] + 360);
        }
        
        int ans = 0;
        int left = 0;
        
        for (int right = 0; right < angles.size(); right++) {
            while (angles[right] - angles[left] > angle) {
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        
        return ans + same;
    }
};