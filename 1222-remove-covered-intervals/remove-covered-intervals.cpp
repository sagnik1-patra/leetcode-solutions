class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Step 1: Sort
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int count = 0;
        int maxEnd = 0;

        // Step 2: Traverse
        for (auto &interval : intervals) {
            if (interval[1] > maxEnd) {
                count++;               // not covered
                maxEnd = interval[1];  // update max end
            }
            // else → covered → skip
        }

        return count;
    }
};