class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min_val = arrays[0][0];
        int max_val = arrays[0].back();
        int max_dist = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            int cur_min = arrays[i][0];
            int cur_max = arrays[i].back();

            max_dist = max({
                max_dist,
                abs(cur_max - min_val),
                abs(max_val - cur_min)
            });

            min_val = min(min_val, cur_min);
            max_val = max(max_val, cur_max);
        }

        return max_dist;
    }
};
