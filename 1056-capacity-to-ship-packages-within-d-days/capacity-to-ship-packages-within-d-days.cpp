class Solution {
public:
    bool canShip(vector<int>& weights, int days, int cap) {
        int usedDays = 1;
        int currLoad = 0;

        for (int w : weights) {
            if (currLoad + w > cap) {
                usedDays++;
                currLoad = 0;
            }
            currLoad += w;
        }

        return usedDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for (int w : weights) high += w;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canShip(weights, days, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
