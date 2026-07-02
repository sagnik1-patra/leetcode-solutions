class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long MOD = 1e9 + 7;

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        long long maxH = horizontalCuts[0];
        long long maxW = verticalCuts[0];

        for (int i = 1; i < horizontalCuts.size(); i++) {
            maxH = max(maxH, (long long)horizontalCuts[i] - horizontalCuts[i - 1]);
        }

        for (int i = 1; i < verticalCuts.size(); i++) {
            maxW = max(maxW, (long long)verticalCuts[i] - verticalCuts[i - 1]);
        }

        maxH = max(maxH, (long long)h - horizontalCuts.back());
        maxW = max(maxW, (long long)w - verticalCuts.back());

        return (maxH * maxW) % MOD;
    }
};