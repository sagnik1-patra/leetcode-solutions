class CountIntervals {
public:
    map<int, int> intervals;
    int total;

    CountIntervals() {
        total = 0;
    }

    void add(int left, int right) {
        auto it = intervals.lower_bound(left);

        // Check the previous interval for overlap
        if (it != intervals.begin()) {
            auto prevIt = prev(it);

            if (prevIt->second >= left) {
                it = prevIt;
            }
        }

        // Merge all overlapping intervals
        while (it != intervals.end() && it->first <= right) {

            left = min(left, it->first);
            right = max(right, it->second);

            // Remove the contribution of the old interval
            total -= it->second - it->first + 1;

            it = intervals.erase(it);
        }

        // Insert the merged interval
        intervals[left] = right;

        // Add the contribution of the merged interval
        total += right - left + 1;
    }

    int count() {
        return total;
    }
};