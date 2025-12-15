class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> maxHeap;
        long long fuel = startFuel;
        int prevPos = 0;
        int stops = 0;

        // Add target as a station with 0 fuel
        stations.push_back({target, 0});

        for (auto& station : stations) {
            int pos = station[0];
            int gas = station[1];

            // Spend fuel to reach this station
            fuel -= (pos - prevPos);

            // Refuel if needed
            while (fuel < 0 && !maxHeap.empty()) {
                fuel += maxHeap.top();
                maxHeap.pop();
                stops++;
            }

            // If still can't reach
            if (fuel < 0) return -1;

            // Add this station's fuel
            maxHeap.push(gas);
            prevPos = pos;
        }

        return stops;
    }
};
