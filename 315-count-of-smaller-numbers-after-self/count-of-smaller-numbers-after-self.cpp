class Solution {
public:
    // Fenwick Tree (Binary Indexed Tree) for prefix sums
    struct BIT {
        int n; 
        vector<int> t;
        BIT(int n): n(n), t(n + 1, 0) {}
        void add(int i, int delta) {           // 1-indexed
            for (; i <= n; i += i & -i) t[i] += delta;
        }
        int sum(int i) const {                  // sum of [1..i]
            int s = 0;
            for (; i > 0; i -= i & -i) s += t[i];
            return s;
        }
    };

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        // Coordinate compression
        vector<int> vals(nums.begin(), nums.end());
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        auto idx = [&](int x) {
            return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1; // 1-indexed
        };

        BIT bit(vals.size());

        // Traverse from right to left
        for (int i = n - 1; i >= 0; --i) {
            int id = idx(nums[i]);
            res[i] = bit.sum(id - 1);   // numbers strictly smaller than nums[i]
            bit.add(id, 1);             // add current number
        }
        return res;
    }
};
