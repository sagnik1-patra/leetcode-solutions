class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < heights.size() - 1; i++) {
            int climb = heights[i + 1] - heights[i];

            // No resource needed
            if (climb <= 0)
                continue;

            // Assume ladder is used for this climb
            pq.push(climb);

            // If we have used more ladders than available,
            // convert the smallest ladder-climb into bricks
            if (pq.size() > ladders) {
                bricks -= pq.top();
                pq.pop();
            }

            // Not enough bricks
            if (bricks < 0)
                return i;
        }

        return heights.size() - 1;
    }
};