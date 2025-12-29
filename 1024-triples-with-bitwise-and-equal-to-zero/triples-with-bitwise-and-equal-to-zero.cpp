class Solution {
public:
    int countTriplets(vector<int>& nums) {
        const int MAX = 1 << 16;
        vector<int> cnt(MAX, 0);

        // Count all pairwise AND results
        for (int a : nums) {
            for (int b : nums) {
                cnt[a & b]++;
            }
        }

        int result = 0;

        // For each number, count compatible AND-pairs
        for (int x : nums) {
            int mask = (~x) & (MAX - 1);

            // Iterate through all submasks of mask
            int sub = mask;
            while (true) {
                result += cnt[sub];
                if (sub == 0) break;
                sub = (sub - 1) & mask;
            }
        }

        return result;
    }
};
