class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        
        // free servers
        set<int> free;
        for (int i = 0; i < k; i++) free.insert(i);
        
        // busy servers → (endTime, server)
        priority_queue<pair<long long, int>, 
                       vector<pair<long long, int>>, 
                       greater<>> busy;
        
        vector<int> count(k, 0);
        
        for (int i = 0; i < n; i++) {
            
            // free servers
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                free.insert(busy.top().second);
                busy.pop();
            }
            
            if (free.empty()) continue;
            
            int target = i % k;
            
            auto it = free.lower_bound(target);
            
            if (it == free.end()) it = free.begin();
            
            int server = *it;
            free.erase(it);
            
            count[server]++;
            
            busy.push({arrival[i] + load[i], server});
        }
        
        int maxReq = *max_element(count.begin(), count.end());
        
        vector<int> result;
        for (int i = 0; i < k; i++) {
            if (count[i] == maxReq) result.push_back(i);
        }
        
        return result;
    }
};