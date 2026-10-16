
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, long long> diff;

        for (auto& s : segments) {
            diff[s[0]] += s[2];
            diff[s[1]] -= s[2];
        }

        vector<vector<long long>> result;
        long long sum = 0;
        int prev = 0;

        for (auto& [pos, change] : diff) {
            if (sum > 0 && prev < pos) {
                result.push_back({prev, pos, sum});
            }

            sum += change;
            prev = pos;
        }

        return result;
    }
};
