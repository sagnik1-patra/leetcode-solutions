class RangeModule {
    map<int, int> intervals; // key: start, value: end

public:
    RangeModule() {}

    // Add [left, right)
    void addRange(int left, int right) {
        auto it = intervals.lower_bound(left);

        // Merge overlapping intervals
        if (it != intervals.begin()) {
            auto itPrev = std::prev(it);
            if (itPrev->second >= left) {
                left = min(left, itPrev->first);
                right = max(right, itPrev->second);
                it = intervals.erase(itPrev);
            }
        }

        while (it != intervals.end() && it->first <= right) {
            right = max(right, it->second);
            it = intervals.erase(it);
        }

        intervals[left] = right;
    }

    // Query if [left, right) is fully covered
    bool queryRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it == intervals.begin()) return false;
        --it;
        return it->second >= right;
    }

    // Remove [left, right)
    void removeRange(int left, int right) {
        auto it = intervals.lower_bound(left);

        if (it != intervals.begin()) {
            auto itPrev = std::prev(it);
            if (itPrev->second > left) {
                int oldEnd = itPrev->second;
                if (itPrev->first < left)
                    intervals[itPrev->first] = left;  // left fragment remains
                else
                    intervals.erase(itPrev);
                if (oldEnd > right)
                    intervals[right] = oldEnd; // right fragment remains
            }
        }

        while (it != intervals.end() && it->first < right) {
            if (it->second > right)
                intervals[right] = it->second;
            it = intervals.erase(it);
        }
    }
};