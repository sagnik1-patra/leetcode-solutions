
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1,
                                 vector<int>& nums2,
                                 long long k) {

        long long low = -10000000000LL;
        long long high = 10000000000LL;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;

            for (long long a : nums1) {
                if (a == 0) {
                    if (mid >= 0) {
                        count += nums2.size();
                    }
                }
                else if (a > 0) {
                    int left = 0;
                    int right = nums2.size();

                    while (left < right) {
                        int m = left + (right - left) / 2;

                        if (a * nums2[m] <= mid)
                            left = m + 1;
                        else
                            right = m;
                    }

                    count += left;
                }
                else {
                    int left = 0;
                    int right = nums2.size();

                    while (left < right) {
                        int m = left + (right - left) / 2;

                        if (a * nums2[m] <= mid)
                            right = m;
                        else
                            left = m + 1;
                    }

                    count += nums2.size() - left;
                }
            }

            if (count >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};
