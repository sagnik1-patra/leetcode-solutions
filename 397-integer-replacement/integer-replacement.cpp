class Solution {
public:
    int integerReplacement(int n) {
        long long x = n;  // avoid overflow when n == INT_MAX
        int steps = 0;
        while (x != 1) {
            if ((x & 1) == 0) {
                x >>= 1;   // divide by 2
            } else {
                if (x == 3 || (x & 2) == 0) x -= 1;
                else x += 1;
            }
            steps++;
        }
        return steps;
    }
};
