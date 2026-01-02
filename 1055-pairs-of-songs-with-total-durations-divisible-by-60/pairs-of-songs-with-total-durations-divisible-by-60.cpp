class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60, 0);
        int ans = 0;

        for (int t : time) {
            int r = t % 60;
            int complement = (60 - r) % 60;
            ans += cnt[complement];
            cnt[r]++;
        }

        return ans;
    }
};
