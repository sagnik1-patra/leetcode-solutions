
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();

        vector<int> indegree(n, 0);
        vector<int> depth(n, 1);

        for (int i = 0; i < n; i++) {
            indegree[favorite[i]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Remove non-cycle nodes and calculate longest chains
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            int v = favorite[u];

            depth[v] = max(depth[v], depth[u] + 1);

            indegree[v]--;

            if (indegree[v] == 0) {
                q.push(v);
            }
        }

        int maxCycle = 0;
        int twoCycleSum = 0;

        // Remaining nodes belong to cycles
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                continue;

            int curr = i;
            int cycleLength = 0;

            while (indegree[curr] != 0) {
                indegree[curr] = 0;
                cycleLength++;
                curr = favorite[curr];
            }

            if (cycleLength == 2) {
                int a = i;
                int b = favorite[i];

                twoCycleSum += depth[a] + depth[b];
            }
            else {
                maxCycle = max(maxCycle, cycleLength);
            }
        }

        return max(maxCycle, twoCycleSum);
    }
};
