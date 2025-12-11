class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int prev = -1;     // index of previous occupied seat
        int maxDist = 0;

        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                // handle leading zeros
                if (prev == -1) {
                    maxDist = i;    // distance from start to first 1
                } else {
                    // middle segment -> take half
                    maxDist = max(maxDist, (i - prev) / 2);
                }
                prev = i; // update last seen occupied seat
            }
        }

        // handle trailing zeros
        maxDist = max(maxDist, n - 1 - prev);

        return maxDist;
    }
};
