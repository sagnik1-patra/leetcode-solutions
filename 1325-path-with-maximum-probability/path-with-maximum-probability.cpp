class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int, double>>> graph(n);

        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            double p = succProb[i];

            graph[a].push_back({b, p});
            graph[b].push_back({a, p});
        }

        vector<double> prob(n, 0.0);
        prob[start] = 1.0;

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});

        while (!pq.empty()) {
            auto [currProb, node] = pq.top();
            pq.pop();

            if (node == end) return currProb;

            if (currProb < prob[node]) continue;

            for (auto [nei, edgeProb] : graph[node]) {
                double newProb = currProb * edgeProb;

                if (newProb > prob[nei]) {
                    prob[nei] = newProb;
                    pq.push({newProb, nei});
                }
            }
        }

        return 0.0;
    }
};