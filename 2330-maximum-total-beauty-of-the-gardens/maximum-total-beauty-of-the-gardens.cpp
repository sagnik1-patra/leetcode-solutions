
class Solution {
public:
    long long maximumBeauty(vector<int>& flowers,
                            long long newFlowers,
                            int target,
                            int full,
                            int partial) {

        int n = flowers.size();

        // Extra flowers beyond target do not matter
        for (int &x : flowers) {
            x = min(x, target);
        }

        sort(flowers.begin(), flowers.end());

        // Prefix sums
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + flowers[i];
        }

        long long ans = 0;
        long long remaining = newFlowers;

        // i = number of gardens left incomplete
        for (int i = n; i >= 0; i--) {

            if (remaining < 0)
                break;

            long long beauty = 1LL * (n - i) * full;

            if (i > 0) {
                int low = flowers[0];
                int high = target - 1;
                int best = 0;

                // Maximize minimum among incomplete gardens
                while (low <= high) {
                    int mid = low + (high - low) / 2;

                    int pos = upper_bound(
                        flowers.begin(),
                        flowers.begin() + i,
                        mid
                    ) - flowers.begin();

                    long long needed =
                        1LL * pos * mid - prefix[pos];

                    if (needed <= remaining) {
                        best = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }

                beauty += 1LL * best * partial;
            }

            ans = max(ans, beauty);

            // Make the next largest incomplete garden complete
            if (i > 0) {
                remaining -= target - flowers[i - 1];
            }
        }

        return ans;
    }
};
