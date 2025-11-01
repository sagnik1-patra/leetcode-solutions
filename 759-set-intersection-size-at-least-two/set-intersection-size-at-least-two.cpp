class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int res = 0;
        int a = -1, b = -1; // last two elements chosen

        for (auto &it : intervals) {
            int l = it[0], r = it[1];

            // Case 1: Both a and b inside interval
            if (l <= a && a <= r && l <= b && b <= r) continue;

            // Case 2: Only b inside interval (need one more)
            else if (l <= b && b <= r) {
                res += 1;
                a = b;
                b = r;
            }

            // Case 3: No overlap (need two new)
            else {
                res += 2;
                a = r - 1;
                b = r;
            }
        }

        return res;
    }
};
