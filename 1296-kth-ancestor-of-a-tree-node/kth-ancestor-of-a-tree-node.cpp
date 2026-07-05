class TreeAncestor {
public:
    vector<vector<int>> up;
    int LOG;

    TreeAncestor(int n, vector<int>& parent) {
        LOG = 20;
        up.resize(n, vector<int>(LOG, -1));

        for (int node = 0; node < n; node++) {
            up[node][0] = parent[node];
        }

        for (int j = 1; j < LOG; j++) {
            for (int node = 0; node < n; node++) {
                int midParent = up[node][j - 1];

                if (midParent != -1) {
                    up[node][j] = up[midParent][j - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                node = up[node][j];

                if (node == -1) {
                    return -1;
                }
            }
        }

        return node;
    }
};