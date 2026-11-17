
class Solution {
public:
    class Fenwick {
    public:
        vector<int> bit;
        int n;

        Fenwick(int size) {
            n = size;
            bit.resize(n + 1, 0);
        }

        void update(int i, int val) {
            i++;
            while (i <= n) {
                bit[i] += val;
                i += i & -i;
            }
        }

        int query(int i) {
            i++;
            int sum = 0;

            while (i > 0) {
                sum += bit[i];
                i -= i & -i;
            }

            return sum;
        }
    };

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[nums2[i]] = i;
        }

        Fenwick bit(n);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int p = pos[nums1[i]];

            long long left = bit.query(p - 1);

            long long right = (n - 1 - p) - (i - left);

            ans += left * right;

            bit.update(p, 1);
        }

        return ans;
    }
};
