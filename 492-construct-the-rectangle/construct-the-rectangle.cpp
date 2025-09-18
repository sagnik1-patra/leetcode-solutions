class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = static_cast<int>(sqrt(area));
        while (w > 0 && area % w != 0) --w;
        return {area / w, w}; // L >= W and L*W == area
    }
};
