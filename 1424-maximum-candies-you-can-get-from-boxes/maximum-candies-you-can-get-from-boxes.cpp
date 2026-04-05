class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {

        int n = status.size();
        
        vector<bool> haveBox(n, false);
        vector<bool> haveKey(n, false);
        vector<bool> visited(n, false);

        queue<int> q;

        // Initialize
        for (int box : initialBoxes) {
            q.push(box);
            haveBox[box] = true;
        }

        int totalCandies = 0;

        while (!q.empty()) {
            int box = q.front();
            q.pop();

            // Skip if already opened
            if (visited[box]) continue;

            // If box is closed and we don't have key → skip for now
            if (status[box] == 0 && !haveKey[box]) continue;

            // Open box
            visited[box] = true;
            totalCandies += candies[box];

            // Collect keys
            for (int k : keys[box]) {
                haveKey[k] = true;

                // If we already have this box and it was locked earlier → try again
                if (haveBox[k] && !visited[k]) {
                    q.push(k);
                }
            }

            // Collect contained boxes
            for (int b : containedBoxes[box]) {
                haveBox[b] = true;
                q.push(b);
            }
        }

        return totalCandies;
    }
};