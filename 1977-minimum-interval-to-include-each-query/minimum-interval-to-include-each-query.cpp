class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals,
                            vector<int>& queries) {

        int n = intervals.size();
        int m = queries.size();

        // Sort intervals by left endpoint
        sort(intervals.begin(), intervals.end());

        // Store {query value, original index}
        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < m; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> answer(m, -1);

        // Min heap storing:
        // {interval size, right endpoint}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        int i = 0;

        for (auto &q : sortedQueries) {

            int query = q.first;
            int index = q.second;

            // Add all intervals whose left endpoint <= query
            while (i < n && intervals[i][0] <= query) {

                int left = intervals[i][0];
                int right = intervals[i][1];

                int size = right - left + 1;

                pq.push({size, right});

                i++;
            }

            // Remove intervals that end before the query
            while (!pq.empty() && pq.top().second < query) {
                pq.pop();
            }

            // Smallest valid interval
            if (!pq.empty()) {
                answer[index] = pq.top().first;
            }
        }

        return answer;
    }
};