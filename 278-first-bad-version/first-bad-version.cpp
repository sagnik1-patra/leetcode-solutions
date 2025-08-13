// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n, ans = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                ans = mid;          // mid could be the first bad
                right = mid - 1;    // look left to find earlier bad
            } else {
                left = mid + 1;     // look right
            }
        }
        return ans;
    }
};
