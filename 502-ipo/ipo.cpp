class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        const int n = profits.size();
        vector<pair<int,int>> proj(n); // (capital_needed, profit)
        for (int i = 0; i < n; ++i) proj[i] = {capital[i], profits[i]};
        sort(proj.begin(), proj.end()); // by capital ascending

        priority_queue<int> pq; // max-heap of profits for affordable projects
        long long cur = w;      // use long long while accumulating
        int i = 0;

        for (int t = 0; t < k; ++t) {
            while (i < n && proj[i].first <= cur) pq.push(proj[i++].second);
            if (pq.empty()) break;      // no affordable projects left
            cur += pq.top(); pq.pop();   // take the most profitable
        }
        return (int)cur; // guaranteed to fit 32-bit
    }
};
