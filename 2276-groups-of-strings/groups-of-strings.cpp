
class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }

    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();

        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);

        unordered_map<int, int> mp;
        unordered_map<int, int> deleted;

        for (int i = 0; i < n; i++) {
            int mask = 0;

            for (char c : words[i]) {
                mask |= (1 << (c - 'a'));
            }

            // Same letter sets
            if (mp.count(mask))
                unite(i, mp[mask]);
            else
                mp[mask] = i;

            // Add or delete one letter
            for (int j = 0; j < 26; j++) {
                int newMask = mask ^ (1 << j);

                if (mp.count(newMask))
                    unite(i, mp[newMask]);
            }

            // Replace one letter
            for (int j = 0; j < 26; j++) {
                if (mask & (1 << j)) {
                    int newMask = mask ^ (1 << j);

                    if (deleted.count(newMask))
                        unite(i, deleted[newMask]);
                    else
                        deleted[newMask] = i;
                }
            }
        }

        int groups = 0;
        int largest = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i) {
                groups++;
                largest = max(largest, sz[i]);
            }
        }

        return {groups, largest};
    }
};
