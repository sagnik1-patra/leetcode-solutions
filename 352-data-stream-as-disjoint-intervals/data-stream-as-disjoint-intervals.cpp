class SummaryRanges {
public:
    SummaryRanges() {}

    void addNum(int val) {
        // Find first interval with start > val
        auto it = intervals.upper_bound(val);

        int L = val, R = val;

        // Try to merge with the interval to the left (if any)
        if (it != intervals.begin()) {
            auto prevIt = prev(it);
            if (prevIt->second >= val) {
                // Already covered by [prevIt->first, prevIt->second]
                return;
            }
            if (prevIt->second + 1 == val) {
                // Merge with left
                L = prevIt->first;
                intervals.erase(prevIt);
            }
        }

        // Try to merge with the interval to the right (if any)
        if (it != intervals.end() && it->first == val + 1) {
            // Merge with right
            R = it->second;
            intervals.erase(it);
        }

        // Insert the merged/new interval
        intervals[L] = R;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        res.reserve(intervals.size());
        for (auto &p : intervals) res.push_back({p.first, p.second});
        return res;
    }

private:
    // key = start, value = end; disjoint, non-adjacent intervals maintained
    std::map<int,int> intervals;
};
