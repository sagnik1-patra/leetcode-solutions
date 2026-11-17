
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long ans = 0;

        for (int num : nums) {
            int g = gcd(num, k);

            for (auto& [prev, freq] : mp) {
                if ((1LL * g * prev) % k == 0) {
                    ans += freq;
                }
            }

            mp[g]++;
        }

        return ans;
    }
};
