class MyCalendar {
    map<int, int> booked; // start -> end

public:
    MyCalendar() {}

    bool book(int start, int end) {
        auto next = booked.lower_bound(start);  // first event with start >= new start

        // Case 1: overlap with the next event
        if (next != booked.end() && next->first < end)
            return false;

        // Case 2: overlap with the previous event
        if (next != booked.begin()) {
            auto itPrev = std::prev(next);
            if (itPrev->second > start)
                return false;
        }

        // No overlap, safe to insert
        booked[start] = end;
        return true;
    }
};