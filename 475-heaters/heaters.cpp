class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        long long ans = 0;
        for (int x : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), x);
            long long d1 = (it == heaters.end()) ? LLONG_MAX : llabs((long long)*it - x);
            long long d2 = (it == heaters.begin()) ? LLONG_MAX : llabs((long long)*(it - 1) - x);
            ans = max(ans, min(d1, d2));
        }
        return (int)ans;
    }
};