
class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int ans = 0;
        int prev = 0;

        for (int rung : rungs) {
            int gap = rung - prev;

            ans += (gap - 1) / dist;

            prev = rung;
        }

        return ans;
    }
};
