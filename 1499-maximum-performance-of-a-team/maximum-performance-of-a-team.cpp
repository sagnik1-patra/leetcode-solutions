class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int MOD = 1e9 + 7;
        
        vector<pair<int,int>> eng;
        for (int i = 0; i < n; i++) {
            eng.push_back({efficiency[i], speed[i]});
        }
        
        // Step 1: sort by efficiency DESC
        sort(eng.rbegin(), eng.rend());
        
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        long long speedSum = 0;
        long long ans = 0;
        
        for (auto &e : eng) {
            int eff = e.first;
            int spd = e.second;
            
            pq.push(spd);
            speedSum += spd;
            
            // maintain at most k engineers
            if (pq.size() > k) {
                speedSum -= pq.top();
                pq.pop();
            }
            
            ans = max(ans, speedSum * eff);
        }
        
        return ans % MOD;
    }
};