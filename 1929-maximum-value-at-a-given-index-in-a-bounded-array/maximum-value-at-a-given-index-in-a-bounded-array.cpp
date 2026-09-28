class Solution {
public:
    long long sideSum(long long peak, long long len) {
        // Values next to peak can be:
        // peak-1, peak-2, ... but cannot go below 1.

        if (peak > len) {
            // All len positions can stay above 0
            long long first = peak - len;
            long long last = peak - 1;

            return (first + last) * len / 2;
        }
        else {
            // Decrease until 1, then remaining positions are 1
            long long decreasing = peak * (peak - 1) / 2;
            long long ones = len - (peak - 1);

            return decreasing + ones;
        }
    }

    int maxValue(int n, int index, int maxSum) {

        long long left = 1;
        long long right = maxSum;
        long long answer = 1;

        while (left <= right) {

            long long mid = left + (right - left) / 2;

            long long leftLen = index;
            long long rightLen = n - index - 1;

            long long total =
                mid +
                sideSum(mid, leftLen) +
                sideSum(mid, rightLen);

            if (total <= maxSum) {
                answer = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return answer;
    }
};