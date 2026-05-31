class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n + 1, 0);
        
        // Step 1: convert to jump-like array
        for (int i = 0; i <= n; i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            maxReach[left] = max(maxReach[left], right);
        }
        
        // Step 2: greedy jump (like Jump Game II)
        int taps = 0, currEnd = 0, farthest = 0;
        
        for (int i = 0; i <= n; i++) {
            if (i > farthest) return -1; // cannot reach
            
            farthest = max(farthest, maxReach[i]);
            
            if (i == currEnd) {
                if (i != n) taps++;
                currEnd = farthest;
            }
        }
        
        return taps;
    }
};