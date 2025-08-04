class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int maxCount = 0;

        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> slopeMap;
            int duplicate = 1;
            int currMax = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicate++;
                } else {
                    int g = gcd(dx, dy);
                    dx /= g;
                    dy /= g;

                    // Normalize slope direction
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                    if (dx == 0) dy = 1;  // vertical line
                    if (dy == 0) dx = 1;  // horizontal line

                    string key = to_string(dy) + "/" + to_string(dx);
                    slopeMap[key]++;
                    currMax = max(currMax, slopeMap[key]);
                }
            }

            maxCount = max(maxCount, currMax + duplicate);
        }

        return maxCount;
    }

private:
    int gcd(int a, int b) {
        return b == 0 ? abs(a) : gcd(b, a % b);
    }
};