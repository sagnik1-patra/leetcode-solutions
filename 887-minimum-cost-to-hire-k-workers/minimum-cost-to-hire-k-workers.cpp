class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;

        // ratio, quality
        for (int i = 0; i < n; i++) {
            workers.push_back({(double)wage[i] / quality[i], quality[i]});
        }

        // sort by ratio
        sort(workers.begin(), workers.end());

        priority_queue<int> maxHeap;
        int qualitySum = 0;
        double ans = DBL_MAX;

        for (auto& w : workers) {
            double ratio = w.first;
            int q = w.second;

            maxHeap.push(q);
            qualitySum += q;

            if (maxHeap.size() > k) {
                qualitySum -= maxHeap.top();
                maxHeap.pop();
            }

            if (maxHeap.size() == k) {
                ans = min(ans, ratio * qualitySum);
            }
        }

        return ans;
    }
};
