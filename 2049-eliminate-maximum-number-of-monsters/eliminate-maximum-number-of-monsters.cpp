
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> arrival(n);

        // Calculate arrival time (rounded up)
        for (int i = 0; i < n; i++) {
            arrival[i] = (dist[i] + speed[i] - 1) / speed[i];
        }

        // Sort by earliest arrival
        sort(arrival.begin(), arrival.end());

        // Eliminate one monster per minute
        for (int i = 0; i < n; i++) {
            if (arrival[i] <= i) {
                return i;
            }
        }

        return n;
    }
};
