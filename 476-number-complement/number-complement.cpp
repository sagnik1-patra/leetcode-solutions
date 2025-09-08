class Solution {
public:
    int findComplement(int num) {
        unsigned mask = 0;
        unsigned x = num;
        while (x) {
            mask = (mask << 1) | 1;
            x >>= 1;
        }
        return (int)(mask ^ num);
    }
};