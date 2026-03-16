class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        
        vector<tuple<int,int,int>> jobs;
        
        for(int i=0;i<n;i++)
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        
        sort(jobs.begin(),jobs.end());
        
        vector<int> starts;
        for(auto &j:jobs)
            starts.push_back(get<0>(j));
        
        vector<long long> dp(n+1,0);
        
        for(int i=n-1;i>=0;i--){
            
            int s = get<0>(jobs[i]);
            int e = get<1>(jobs[i]);
            int p = get<2>(jobs[i]);
            
            int next = lower_bound(starts.begin(),starts.end(),e) - starts.begin();
            
            dp[i] = max(dp[i+1], p + dp[next]);
        }
        
        return dp[0];
    }
};