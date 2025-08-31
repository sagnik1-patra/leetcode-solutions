class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long mn = LLONG_MAX, sum = 0;
        for (int x : nums) {
            mn = min(mn, (long long)x);
            sum += x;
        }
        return (int)(sum - mn * (long long)nums.size());
    }
};
