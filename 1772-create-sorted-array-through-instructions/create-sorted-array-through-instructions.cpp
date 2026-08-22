class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        const int MOD = 1e9 + 7;
        int maxVal = 100000;

        vector<int> bit(maxVal + 2, 0);

        auto update = [&](int index) {
            while (index <= maxVal + 1) {
                bit[index]++;
                index += index & -index;
            }
        };

        auto query = [&](int index) {
            int sum = 0;
            while (index > 0) {
                sum += bit[index];
                index -= index & -index;
            }
            return sum;
        };

        long long ans = 0;

        for (int i = 0; i < instructions.size(); i++) {
            int x = instructions[i];

            int less = query(x - 1);
            int lessOrEqual = query(x);
            int greater = i - lessOrEqual;

            ans = (ans + min(less, greater)) % MOD;

            update(x);
        }

        return ans;
    }
};