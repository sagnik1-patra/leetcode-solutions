
class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa != pb)
            parent[pa] = pb;
    }

    bool gcdSort(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        parent.resize(mx + 1);

        for (int i = 0; i <= mx; i++)
            parent[i] = i;

        // Smallest Prime Factor
        vector<int> spf(mx + 1);

        for (int i = 0; i <= mx; i++)
            spf[i] = i;

        for (int i = 2; i * i <= mx; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= mx; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        // Connect each number with its prime factors
        for (int num : nums) {
            int x = num;

            while (x > 1) {
                int p = spf[x];

                unite(num, p);

                while (x % p == 0)
                    x /= p;
            }
        }

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        for (int i = 0; i < nums.size(); i++) {
            if (find(nums[i]) != find(sorted[i]))
                return false;
        }

        return true;
    }
};
