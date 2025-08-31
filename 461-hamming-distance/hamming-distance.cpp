class Solution {
public:
    int hammingDistance(int x, int y) {
        unsigned int z = x ^ y;
        int cnt = 0;
        while (z) {
            z &= (z - 1); // clear lowest set bit
            ++cnt;
        }
        return cnt;
    }
};
