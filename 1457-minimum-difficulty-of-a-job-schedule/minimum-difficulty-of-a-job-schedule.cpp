class Solution {
public:
    int n;
    vector<vector<int>> dp;
    
    int solve(int i, int days, vector<int>& job) {
        if (days == 1) {
            return *max_element(job.begin() + i, job.end());
        }
        
        if (dp[i][days] != -1) return dp[i][days];
        
        int res = INT_MAX;
        int currMax = 0;
        
        // try splitting
        for (int j = i; j <= n - days; j++) {
            currMax = max(currMax, job[j]);
            
            int next = solve(j + 1, days - 1, job);
            res = min(res, currMax + next);
        }
        
        return dp[i][days] = res;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        
        if (n < d) return -1;
        
        dp.assign(n, vector<int>(d + 1, -1));
        
        return solve(0, d, jobDifficulty);
    }
};