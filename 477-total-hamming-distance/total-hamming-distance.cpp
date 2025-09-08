class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        long long ans = 0;
        int n = (int)nums.size();

        for (int b = 0; b < 31; ++b) {        // bits 0..30 cover up to 1e9
            int ones = 0;
            for (int x : nums) {
                ones += (x >> b) & 1;
            }
            ans += 1LL * ones * (n - ones);
        }
        return (int)ans;
    }
};