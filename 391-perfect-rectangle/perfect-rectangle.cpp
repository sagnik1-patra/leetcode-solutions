class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        using ll = long long;

        // bounding box
        int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
        unordered_set<string> corners;
        auto key = [](int x, int y) { return to_string(x) + "#" + to_string(y); };

        ll areaSum = 0;
        for (auto& r : rectangles) {
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];

            // update bounding box
            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);

            // accumulate area
            areaSum += (ll)(x2 - x1) * (ll)(y2 - y1);

            // flip each of the 4 corners
            string c1 = key(x1, y1);
            string c2 = key(x1, y2);
            string c3 = key(x2, y1);
            string c4 = key(x2, y2);
            for (auto& c : {c1, c2, c3, c4}) {
                if (!corners.insert(c).second) corners.erase(c);
            }
        }

        // area must match big rectangle area
        ll bigArea = (ll)(maxX - minX) * (ll)(maxY - minY);
        if (areaSum != bigArea) return false;

        // corners must be exactly the 4 corners of the bounding box
        if (corners.size() != 4) return false;
        if (!corners.count(key(minX, minY))) return false;
        if (!corners.count(key(minX, maxY))) return false;
        if (!corners.count(key(maxX, minY))) return false;
        if (!corners.count(key(maxX, maxY))) return false;

        return true;
    }
};
