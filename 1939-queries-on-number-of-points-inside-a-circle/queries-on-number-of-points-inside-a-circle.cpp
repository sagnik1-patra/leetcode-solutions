class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points,
                            vector<vector<int>>& queries) {
        
        vector<int> answer;

        for (auto& q : queries) {
            int x = q[0];
            int y = q[1];
            int r = q[2];

            int count = 0;

            for (auto& p : points) {
                int dx = p[0] - x;
                int dy = p[1] - y;

                if (dx * dx + dy * dy <= r * r) {
                    count++;
                }
            }

            answer.push_back(count);
        }

        return answer;
    }
};