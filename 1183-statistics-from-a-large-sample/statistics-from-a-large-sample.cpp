class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double minVal = -1, maxVal = -1;
        double mean = 0, median = 0, mode = 0;

        long long total = 0;
        long long sum = 0;
        int maxCount = 0;

        // First pass: min, max, mean, mode
        for (int i = 0; i < 256; i++) {
            if (count[i] > 0) {
                if (minVal == -1) minVal = i;
                maxVal = i;
                sum += (long long)i * count[i];
                total += count[i];

                if (count[i] > maxCount) {
                    maxCount = count[i];
                    mode = i;
                }
            }
        }

        mean = (double)sum / total;

        // Second pass: median
        long long curr = 0;
        if (total % 2 == 1) {
            long long mid = total / 2 + 1;
            for (int i = 0; i < 256; i++) {
                curr += count[i];
                if (curr >= mid) {
                    median = i;
                    break;
                }
            }
        } else {
            long long mid1 = total / 2;
            long long mid2 = mid1 + 1;
            double m1 = 0, m2 = 0;

            for (int i = 0; i < 256; i++) {
                curr += count[i];
                if (curr >= mid1 && m1 == 0) m1 = i;
                if (curr >= mid2) {
                    m2 = i;
                    break;
                }
            }
            median = (m1 + m2) / 2.0;
        }

        return {minVal, maxVal, mean, median, mode};
    }
};
