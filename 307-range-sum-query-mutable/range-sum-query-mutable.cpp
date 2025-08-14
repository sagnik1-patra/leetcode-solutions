class NumArray {
public:
    NumArray(vector<int>& nums) : n(nums.size()), bit(n + 1, 0), arr(nums) {
        // build Fenwick Tree
        for (int i = 0; i < n; ++i) add(i + 1, arr[i]);
    }

    void update(int index, int val) {
        int delta = val - arr[index];
        arr[index] = val;
        add(index + 1, delta);
    }

    int sumRange(int left, int right) {
        return prefix(right + 1) - prefix(left);
    }

private:
    int n;
    vector<int> bit, arr;

    // add value to position i (1-indexed)
    void add(int i, int delta) {
        for (; i <= n; i += i & -i) bit[i] += delta;
    }
    // sum of [1..i) in 1-indexed space (i.e., 0..i-1 in 0-indexed)
    int prefix(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};
