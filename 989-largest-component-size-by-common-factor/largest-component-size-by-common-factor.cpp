class Solution {
public:
    vector<int> parent, size;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (size[px] < size[py])
            swap(px, py);

        parent[py] = px;
        size[px] += size[py];
    }

    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        unordered_map<int, int> factorOwner;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int f = 2; f * f <= x; f++) {
                if (x % f == 0) {
                    if (factorOwner.count(f))
                        unite(i, factorOwner[f]);
                    else
                        factorOwner[f] = i;

                    while (x % f == 0)
                        x /= f;
                }
            }
            // remaining prime factor
            if (x > 1) {
                if (factorOwner.count(x))
                    unite(i, factorOwner[x]);
                else
                    factorOwner[x] = i;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                ans = max(ans, size[i]);
        }

        return ans;
    }
};
