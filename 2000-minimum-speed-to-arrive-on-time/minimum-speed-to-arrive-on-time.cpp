class Solution {
public:
    bool canReach(vector<int>& dist, double hour, int speed) {
        double time = 0.0;
        int n = dist.size();

        // For every train except the last one,
        // we must wait until the next integer hour.
        for (int i = 0; i < n - 1; i++) {
            time += ceil((double)dist[i] / speed);
        }

        // No waiting is needed after the last train.
        time += (double)dist[n - 1] / speed;

        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();

        // At least n-1 hours are needed before taking
        // the final train.
        if (hour <= n - 1) {
            return -1;
        }

        int left = 1;
        int right = 10000000;

        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canReach(dist, hour, mid)) {
                answer = mid;

                // Try a smaller speed
                right = mid - 1;
            }
            else {
                // Need a higher speed
                left = mid + 1;
            }
        }

        return answer;
    }
};