class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> g;
        int m = equations.size();
        for (int i = 0; i < m; ++i) {
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            double v = values[i];
            g[A].push_back({B, v});
            g[B].push_back({A, 1.0 / v});
        }

        vector<double> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            const string& C = q[0];
            const string& D = q[1];
            if (!g.count(C) || !g.count(D)) { ans.push_back(-1.0); continue; }
            if (C == D) { ans.push_back(1.0); continue; }

            unordered_set<string> vis;
            double res = -1.0;
            if (dfs(C, D, 1.0, g, vis, res)) ans.push_back(res);
            else ans.push_back(-1.0);
        }
        return ans;
    }

private:
    bool dfs(const string& u, const string& target, double prod,
             unordered_map<string, vector<pair<string,double>>>& g,
             unordered_set<string>& vis, double& out) {
        if (u == target) { out = prod; return true; }
        vis.insert(u);
        for (auto& [v, w] : g[u]) {
            if (vis.count(v)) continue;
            if (dfs(v, target, prod * w, g, vis, out)) return true;
        }
        return false;
    }
};
