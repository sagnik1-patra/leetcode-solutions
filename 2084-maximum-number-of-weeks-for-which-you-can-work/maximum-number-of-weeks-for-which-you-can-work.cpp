
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long total = 0;
        long long maxi = 0;

        for (int m : milestones) {
            total += m;
            maxi = max(maxi, (long long)m);
        }

        long long remaining = total - maxi;

        if (maxi <= remaining + 1) {
            return total;
        }

        return 2 * remaining + 1;
    }
};
