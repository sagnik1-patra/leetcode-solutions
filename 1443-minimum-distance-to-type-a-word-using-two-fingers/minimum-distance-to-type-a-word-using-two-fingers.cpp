class Solution {
public:
    int dist(int a, int b) {
        if (a == -1) return 0; // free placement
        
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        
        return abs(x1 - x2) + abs(y1 - y2);
    }
    
    int minimumDistance(string word) {
        int n = word.size();
        
        vector<int> dp(26, 0); // all 0 → free start
        
        for (int i = 0; i < n - 1; i++) {
            int curr = word[i] - 'A';
            int next = word[i + 1] - 'A';
            
            vector<int> new_dp(26, INT_MAX);
            
            for (int j = 0; j < 26; j++) {
                // move same finger
                new_dp[j] = min(new_dp[j], dp[j] + dist(curr, next));
                
                // move other finger (j → next)
                new_dp[curr] = min(new_dp[curr], dp[j] + dist(j, next));
            }
            
            dp = new_dp;
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};