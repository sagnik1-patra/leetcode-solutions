class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        // Map each bus stop to all routes (bus indices) passing through it
        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }

        queue<pair<int, int>> q;  // {stop, buses_taken}
        unordered_set<int> visitedStops;
        unordered_set<int> visitedRoutes;

        q.push({source, 0});
        visitedStops.insert(source);

        while (!q.empty()) {
            auto [stop, buses] = q.front();
            q.pop();

            // Explore all routes passing through this stop
            for (int route : stopToRoutes[stop]) {
                if (visitedRoutes.count(route)) continue;
                visitedRoutes.insert(route);

                // Explore all stops in this route
                for (int nextStop : routes[route]) {
                    if (nextStop == target) return buses + 1;
                    if (!visitedStops.count(nextStop)) {
                        visitedStops.insert(nextStop);
                        q.push({nextStop, buses + 1});
                    }
                }
            }
        }

        return -1; // not reachable
    }
};