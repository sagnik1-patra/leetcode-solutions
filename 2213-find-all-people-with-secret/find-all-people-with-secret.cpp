class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[2] < b[2];
             });

        vector<bool> knows(n, false);
        knows[0] = true;
        knows[firstPerson] = true;

        int i = 0;
        int m = meetings.size();

        while (i < m) {
            int time = meetings[i][2];

            unordered_map<int, vector<int>> adj;
            queue<int> q;
            unordered_set<int> visited;

            // Group meetings happening at the same time
            while (i < m && meetings[i][2] == time) {
                int u = meetings[i][0];
                int v = meetings[i][1];

                adj[u].push_back(v);
                adj[v].push_back(u);

                if (knows[u] && !visited.count(u)) {
                    q.push(u);
                    visited.insert(u);
                }

                if (knows[v] && !visited.count(v)) {
                    q.push(v);
                    visited.insert(v);
                }

                i++;
            }

            // Spread secret using BFS
            while (!q.empty()) {
                int person = q.front();
                q.pop();

                knows[person] = true;

                for (int neighbor : adj[person]) {
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }

        vector<int> ans;

        for (int j = 0; j < n; j++) {
            if (knows[j]) {
                ans.push_back(j);
            }
        }

        return ans;
    }
};