class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py)
            parent[px] = py;
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        parent.resize(4 * n * n);

        for (int i = 0; i < parent.size(); i++)
            parent[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int idx = (i * n + j) * 4;
                char c = grid[i][j];

                // internal connections
                if (c == ' ') {
                    unite(idx + 0, idx + 1);
                    unite(idx + 1, idx + 2);
                    unite(idx + 2, idx + 3);
                } else if (c == '/') {
                    unite(idx + 0, idx + 3);
                    unite(idx + 1, idx + 2);
                } else { // '\'
                    unite(idx + 0, idx + 1);
                    unite(idx + 2, idx + 3);
                }

                // connect to bottom cell
                if (i + 1 < n) {
                    unite(idx + 2, ((i + 1) * n + j) * 4 + 0);
                }

                // connect to right cell
                if (j + 1 < n) {
                    unite(idx + 1, (i * n + j + 1) * 4 + 3);
                }
            }
        }

        int regions = 0;
        for (int i = 0; i < parent.size(); i++) {
            if (find(i) == i)
                regions++;
        }

        return regions;
    }
};
