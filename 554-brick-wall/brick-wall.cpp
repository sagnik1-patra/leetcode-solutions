class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> edgeCount;
        int maxEdges = 0;

        for (auto& row : wall) {
            long long sum = 0;
            // exclude the last brick
            for (int i = 0; i < row.size() - 1; i++) {
                sum += row[i];
                edgeCount[sum]++;
                maxEdges = max(maxEdges, edgeCount[sum]);
            }
        }

        return wall.size() - maxEdges;
    }
};