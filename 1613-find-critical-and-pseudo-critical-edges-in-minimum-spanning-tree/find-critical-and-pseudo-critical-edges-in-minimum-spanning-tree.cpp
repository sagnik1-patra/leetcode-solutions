class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (rank[a] < rank[b]) swap(a, b);

        parent[b] = a;

        if (rank[a] == rank[b]) rank[a]++;

        return true;
    }
};

class Solution {
public:
    int kruskal(int n, vector<vector<int>>& edges, int skip, int force) {
        DSU dsu(n);
        int weight = 0;
        int count = 0;

        if (force != -1) {
            auto &e = edges[force];

            if (dsu.unite(e[0], e[1])) {
                weight += e[2];
                count++;
            }
        }

        for (int i = 0; i < edges.size(); i++) {
            if (i == skip) continue;

            auto &e = edges[i];

            if (dsu.unite(e[0], e[1])) {
                weight += e[2];
                count++;
            }
        }

        if (count != n - 1) return 1e9;

        return weight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();

        for (int i = 0; i < m; i++) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        int mstWeight = kruskal(n, edges, -1, -1);

        vector<int> critical;
        vector<int> pseudo;

        for (int i = 0; i < m; i++) {
            int withoutEdge = kruskal(n, edges, i, -1);

            if (withoutEdge > mstWeight) {
                critical.push_back(edges[i][3]);
            } else {
                int withEdge = kruskal(n, edges, -1, i);

                if (withEdge == mstWeight) {
                    pseudo.push_back(edges[i][3]);
                }
            }
        }

        return {critical, pseudo};
    }
};