
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> even, odd;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                even[nums[i]]++;
            else
                odd[nums[i]]++;
        }

        vector<pair<int, int>> e, o;

        for (auto [num, freq] : even)
            e.push_back({freq, num});

        for (auto [num, freq] : odd)
            o.push_back({freq, num});

        sort(e.rbegin(), e.rend());
        sort(o.rbegin(), o.rend());

        e.push_back({0, -1});
        o.push_back({0, -1});

        int keep = 0;

        if (e[0].second != o[0].second) {
            keep = e[0].first + o[0].first;
        } else {
            keep = max(
                e[0].first + o[1].first,
                e[1].first + o[0].first
            );
        }

        return n - keep;
    }
};
