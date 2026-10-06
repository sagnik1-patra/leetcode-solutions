class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> availableSeats;

public:
    SeatManager(int n) {
        // Initially all seats are available
        for (int i = 1; i <= n; i++) {
            availableSeats.push(i);
        }
    }

    int reserve() {
        // Get the smallest available seat
        int seat = availableSeats.top();
        availableSeats.pop();

        return seat;
    }

    void unreserve(int seatNumber) {
        // Make the seat available again
        availableSeats.push(seatNumber);
    }
};