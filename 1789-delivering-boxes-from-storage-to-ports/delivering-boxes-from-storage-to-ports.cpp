class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount,
                      int maxBoxes, int maxWeight) {
        
        int n = boxes.size();

        vector<int> dp(n + 1, 0);
        vector<int> portChanges(n + 1, 0);

        // FIX: use long long because sum of weights can exceed int
        vector<long long> prefixWeight(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefixWeight[i] =
                prefixWeight[i - 1] + (long long)boxes[i - 1][1];

            portChanges[i] = portChanges[i - 1];

            if (i > 1 && boxes[i - 1][0] != boxes[i - 2][0]) {
                portChanges[i]++;
            }
        }

        deque<int> dq;
        dq.push_back(0);

        for (int i = 1; i <= n; i++) {

            // Remove starting points that violate
            // maxBoxes or maxWeight
            while (!dq.empty()) {
                int j = dq.front();

                int boxCount = i - j;

                // FIX: long long
                long long totalWeight =
                    prefixWeight[i] - prefixWeight[j];

                if (boxCount > maxBoxes ||
                    totalWeight > (long long)maxWeight) {
                    dq.pop_front();
                } else {
                    break;
                }
            }

            int j = dq.front();

            // Deliver boxes j ... i-1
            dp[i] = dp[j]
                  + portChanges[i]
                  - portChanges[j + 1]
                  + 2;

            if (i == n)
                continue;

            // Maintain monotonic deque
            int currentValue =
                dp[i] - portChanges[i + 1];

            while (!dq.empty()) {
                int k = dq.back();

                int backValue =
                    dp[k] - portChanges[k + 1];

                if (currentValue <= backValue) {
                    dq.pop_back();
                } else {
                    break;
                }
            }

            dq.push_back(i);
        }

        return dp[n];
    }
};