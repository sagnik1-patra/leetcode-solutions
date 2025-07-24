class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        // Step 1: Sort intervals based on the starting times
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            // Compare current interval with the last one in merged
            if (intervals[i][0] <= merged.back()[1]) {
                // Overlapping intervals, merge them
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                // No overlap, add the current interval
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
