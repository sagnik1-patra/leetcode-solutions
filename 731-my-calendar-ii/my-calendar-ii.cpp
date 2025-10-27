class MyCalendarTwo {
    vector<pair<int, int>> booked;   // all single bookings
    vector<pair<int, int>> overlaps; // all double bookings

public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        // Step 1: Check if it causes triple booking
        for (auto &p : overlaps) {
            int l = max(start, p.first);
            int r = min(end, p.second);
            if (l < r)  // overlap found with already double-booked interval
                return false;
        }

        // Step 2: Record new double-booked intervals
        for (auto &p : booked) {
            int l = max(start, p.first);
            int r = min(end, p.second);
            if (l < r)
                overlaps.push_back({l, r});
        }

        // Step 3: Add this event to booked
        booked.push_back({start, end});
        return true;
    }
};
