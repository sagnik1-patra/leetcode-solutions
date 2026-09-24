class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        // Sort events by starting day
        sort(events.begin(), events.end());

        int n = events.size();

        // Store starting days for binary search
        vector<int> startDays(n);

        for (int i = 0; i < n; i++) {
            startDays[i] = events[i][0];
        }

        // nextEvent[i] = first event whose start day
        // is strictly greater than events[i]'s end day
        vector<int> nextEvent(n);

        for (int i = 0; i < n; i++) {
            int endDay = events[i][1];

            nextEvent[i] =
                upper_bound(
                    startDays.begin(),
                    startDays.end(),
                    endDay
                ) - startDays.begin();
        }

        // dp[i] = maximum value starting from event i
        // for the previous number of allowed events
        vector<int> previous(n + 1, 0);
        vector<int> current(n + 1, 0);

        for (int count = 1; count <= k; count++) {

            for (int i = n - 1; i >= 0; i--) {

                // Skip current event
                int skip = current[i + 1];

                // Attend current event
                int take =
                    events[i][2] +
                    previous[nextEvent[i]];

                current[i] = max(skip, take);
            }

            previous = current;
        }

        return previous[0];
    }
};