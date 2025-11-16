class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        int n = difficulty.size();

        for (int i = 0; i < n; i++)
            jobs.push_back({difficulty[i], profit[i]});

        // Sort jobs by difficulty
        sort(jobs.begin(), jobs.end());

        // Sort workers by their ability
        sort(worker.begin(), worker.end());

        int totalProfit = 0;
        int bestProfit = 0;
        int i = 0;

        // Iterate through each worker (in increasing order of ability)
        for (int w : worker) {
            while (i < n && jobs[i].first <= w) {
                bestProfit = max(bestProfit, jobs[i].second);
                i++;
            }
            totalProfit += bestProfit;
        }

        return totalProfit;
    }
};