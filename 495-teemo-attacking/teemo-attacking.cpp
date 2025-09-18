class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty() || duration == 0) return 0;
        long long total = 0;
        for (int i = 0; i + 1 < (int)timeSeries.size(); ++i) {
            total += min<long long>(duration, (long long)timeSeries[i + 1] - timeSeries[i]);
        }
        total += duration; // last attack always contributes full duration
        return (int)total;
    }
};
