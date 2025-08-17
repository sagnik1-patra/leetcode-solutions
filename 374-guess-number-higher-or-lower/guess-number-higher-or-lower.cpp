// Forward declaration of guess API.
// int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long lo = 1, hi = n;   // use long long to avoid overflow on mid calc
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            int g = guess((int)mid);
            if (g == 0) return (int)mid;
            else if (g < 0) hi = mid - 1;   // our guess is higher
            else lo = mid + 1;              // our guess is lower
        }
        return -1; // should never hit due to problem guarantees
    }
};
