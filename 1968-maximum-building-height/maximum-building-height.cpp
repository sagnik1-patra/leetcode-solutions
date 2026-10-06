class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        // Building 1 must have height 0
        restrictions.push_back({1, 0});

        // Sort restrictions by building id
        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // Left to right:
        // adjust restrictions based on previous restriction
        for (int i = 1; i < m; i++) {

            int distance =
                restrictions[i][0] - restrictions[i - 1][0];

            restrictions[i][1] =
                min(restrictions[i][1],
                    restrictions[i - 1][1] + distance);
        }

        // Right to left:
        // adjust restrictions based on next restriction
        for (int i = m - 2; i >= 0; i--) {

            int distance =
                restrictions[i + 1][0] - restrictions[i][0];

            restrictions[i][1] =
                min(restrictions[i][1],
                    restrictions[i + 1][1] + distance);
        }

        long long answer = 0;

        // Find maximum possible peak between restrictions
        for (int i = 1; i < m; i++) {

            long long x1 = restrictions[i - 1][0];
            long long h1 = restrictions[i - 1][1];

            long long x2 = restrictions[i][0];
            long long h2 = restrictions[i][1];

            long long distance = x2 - x1;

            long long peak =
                (h1 + h2 + distance) / 2;

            answer = max(answer, peak);
        }

        // Buildings after the final restriction
        long long lastId = restrictions[m - 1][0];
        long long lastHeight = restrictions[m - 1][1];

        answer = max(
            answer,
            lastHeight + (n - lastId)
        );

        return (int)answer;
    }
};