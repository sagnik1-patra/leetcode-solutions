class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> pq;
        long long total = 0;
        
        // Step 1: initialize
        for (int x : target) {
            pq.push(x);
            total += x;
        }
        
        while (true) {
            long long maxVal = pq.top(); pq.pop();
            long long rest = total - maxVal;
            
            // base cases
            if (maxVal == 1 || rest == 1) return true;
            if (rest == 0 || maxVal <= rest) return false;
            
            long long prev = maxVal % rest;
            
            if (prev == 0) return false;
            
            // update
            pq.push(prev);
            total = rest + prev;
        }
    }
};