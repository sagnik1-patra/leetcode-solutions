class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    vector<bool> friendRequests(int n,
                                vector<vector<int>>& restrictions,
                                vector<vector<int>>& requests) {

        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        vector<bool> ans;

        for (auto& req : requests) {
            int u = find(req[0]);
            int v = find(req[1]);

            bool possible = true;

            for (auto& r : restrictions) {
                int x = find(r[0]);
                int y = find(r[1]);

                if ((u == x && v == y) ||
                    (u == y && v == x)) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                parent[u] = v;
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};