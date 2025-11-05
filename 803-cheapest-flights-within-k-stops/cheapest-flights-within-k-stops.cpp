class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Adjacency list: node -> list of (next, price)
        vector<vector<pair<int, int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // minCost[node] = minimum cost to reach node within given stops
        vector<int> minCost(n, INT_MAX);
        queue<pair<int, pair<int, int>>> q; // {stops, {node, cost}}

        q.push({0, {src, 0}});
        minCost[src] = 0;

        while (!q.empty()) {
            auto [stops, p] = q.front();
            q.pop();
            int node = p.first;
            int cost = p.second;

            // If we already exceeded max stops, skip
            if (stops > k) continue;

            // Traverse neighbors
            for (auto &next : adj[node]) {
                int neighbor = next.first;
                int price = next.second;

                int newCost = cost + price;

                // If cheaper cost found within allowed stops
                if (newCost < minCost[neighbor]) {
                    minCost[neighbor] = newCost;
                    q.push({stops + 1, {neighbor, newCost}});
                }
            }
        }

        return (minCost[dst] == INT_MAX) ? -1 : minCost[dst];
    }
};