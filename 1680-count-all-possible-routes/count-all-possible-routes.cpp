class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    
    int solve(int i, int fuel, vector<int>& loc, int finish) {
        if (fuel < 0) return 0;
        
        if (dp[i][fuel] != -1) return dp[i][fuel];
        
        long long ways = (i == finish) ? 1 : 0;
        
        for (int j = 0; j < loc.size(); j++) {
            if (j == i) continue;
            
            int cost = abs(loc[i] - loc[j]);
            
            if (fuel >= cost) {
                ways += solve(j, fuel - cost, loc, finish);
                ways %= MOD;
            }
        }
        
        return dp[i][fuel] = ways;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        dp.assign(n, vector<int>(fuel + 1, -1));
        
        return solve(start, fuel, locations, finish);
    }
};