class ExamRoom {
public:
    int N;
    set<int> seats;

    ExamRoom(int n) {
        N = n;
    }

    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }

        int maxDist = 0;
        int bestSeat = 0;

        // Check left edge
        int first = *seats.begin();
        if (first > maxDist) {
            maxDist = first;
            bestSeat = 0;
        }

        // Check middle gaps
        int prev = -1;
        for (int curr : seats) {
            if (prev != -1) {
                int dist = (curr - prev) / 2;
                int candidate = prev + dist;
                if (dist > maxDist) {
                    maxDist = dist;
                    bestSeat = candidate;
                }
            }
            prev = curr;
        }

        // Check right edge
        int last = *seats.rbegin();
        if ((N - 1 - last) > maxDist) {
            bestSeat = N - 1;
        }

        seats.insert(bestSeat);
        return bestSeat;
    }

    void leave(int p) {
        seats.erase(p);
    }
};
