class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        long long total = 0;
        for (int x : machines) total += x;
        int n = machines.size();
        if (total % n != 0) return -1;            // impossible

        int avg = total / n;
        long long prefix = 0;                      // net flow through prefix [0..i]
        long long ans = 0;

        for (int x : machines) {
            long long diff = (long long)x - avg;   // surplus(+) / deficit(-)
            prefix += diff;
            ans = std::max(ans, std::max(std::llabs(prefix), diff));
        }
        return (int)ans;
    }
};
