class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int baseSatisfied = 0;

        // Step 1: customers already satisfied
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                baseSatisfied += customers[i];
            }
        }

        // Step 2: sliding window to maximize extra satisfaction
        int extra = 0, maxExtra = 0;

        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 1) {
                extra += customers[i];
            }

            if (i >= minutes && grumpy[i - minutes] == 1) {
                extra -= customers[i - minutes];
            }

            maxExtra = max(maxExtra, extra);
        }

        return baseSatisfied + maxExtra;
    }
};
