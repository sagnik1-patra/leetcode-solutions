class Solution {
public:
    bool canWinNim(int n) {
        // First player loses only when n is a multiple of 4
        return n % 4 != 0;
    }
};
