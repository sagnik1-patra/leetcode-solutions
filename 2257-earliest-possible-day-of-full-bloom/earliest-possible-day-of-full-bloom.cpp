
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime,
                          vector<int>& growTime) {

        int n = plantTime.size();

        vector<pair<int, int>> seeds;

        for (int i = 0; i < n; i++) {
            seeds.push_back({growTime[i], plantTime[i]});
        }

        // Sort by decreasing growTime
        sort(seeds.rbegin(), seeds.rend());

        int days = 0;
        int ans = 0;

        for (auto [grow, plant] : seeds) {
            days += plant;
            ans = max(ans, days + grow);
        }

        return ans;
    }
};
