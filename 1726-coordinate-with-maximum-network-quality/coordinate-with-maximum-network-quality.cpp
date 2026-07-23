class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int maxQuality = 0;
        vector<int> result = {0, 0};
        
        for (int x = 0; x <= 50; x++) {
            for (int y = 0; y <= 50; y++) {
                
                int total = 0;
                
                for (auto &t : towers) {
                    int xi = t[0], yi = t[1], qi = t[2];
                    
                    double dist = sqrt((x - xi) * (x - xi) + (y - yi) * (y - yi));
                    
                    if (dist <= radius) {
                        total += floor(qi / (1 + dist));
                    }
                }
                
                if (total > maxQuality) {
                    maxQuality = total;
                    result = {x, y};
                }
            }
        }
        
        return result;
    }
};