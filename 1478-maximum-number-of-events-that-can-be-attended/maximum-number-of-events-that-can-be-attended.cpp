class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int day = 0, i = 0, n = events.size();
        int attended = 0;
        
        while (i < n || !pq.empty()) {
            
            // if no active events → jump to next start day
            if (pq.empty()) {
                day = events[i][0];
            }
            
            // add all events starting today
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }
            
            // remove expired events
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            
            // attend one event
            if (!pq.empty()) {
                pq.pop();
                attended++;
                day++;
            }
        }
        
        return attended;
    }
};