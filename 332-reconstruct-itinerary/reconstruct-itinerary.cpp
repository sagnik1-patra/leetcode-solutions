class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build graph: from -> min-heap of destinations (to pick smallest lexical first)
        unordered_map<string,
            priority_queue<string, vector<string>, greater<string>>> adj;
        adj.reserve(tickets.size() * 2);

        for (auto& t : tickets) adj[t[0]].push(t[1]);

        vector<string> route; route.reserve(tickets.size() + 1);
        dfs("JFK", adj, route);
        reverse(route.begin(), route.end());
        return route;
    }

private:
    void dfs(const string& u,
             unordered_map<string,
                priority_queue<string, vector<string>, greater<string>>>& adj,
             vector<string>& route)
    {
        auto& pq = adj[u];
        while (!pq.empty()) {
            string v = pq.top(); pq.pop();
            dfs(v, adj, route);
        }
        // add airport when no further edges — Hierholzer's algorithm
        route.push_back(u);
    }
};
