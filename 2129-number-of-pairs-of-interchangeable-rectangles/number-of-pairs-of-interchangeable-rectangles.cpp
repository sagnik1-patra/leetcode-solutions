
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<pair<int, int>, long long> freq;
        long long count = 0;

        for (auto& rect : rectangles) {
            int w = rect[0];
            int h = rect[1];

            int g = gcd(w, h);

            w /= g;
            h /= g;

            count += freq[{w, h}];
            freq[{w, h}]++;
        }

        return count;
    }
};
