class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);

        // Apply range updates
        for (auto &b : bookings) {
            int first = b[0];
            int last = b[1];
            int seats = b[2];

            diff[first - 1] += seats;
            diff[last] -= seats;
        }

        // Build prefix sum to get final result
        vector<int> ans(n, 0);
        int running = 0;
        for (int i = 0; i < n; i++) {
            running += diff[i];
            ans[i] = running;
        }

        return ans;
    }
};
