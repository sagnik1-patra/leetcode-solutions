class Solution {
public:
    unordered_map<int, int> dp;
    
    int minDays(int n) {
        if (n <= 1) return n;
        
        if (dp.count(n)) return dp[n];
        
        int by2 = (n % 2) + minDays(n / 2);
        int by3 = (n % 3) + minDays(n / 3);
        
        return dp[n] = 1 + min(by2, by3);
    }
};