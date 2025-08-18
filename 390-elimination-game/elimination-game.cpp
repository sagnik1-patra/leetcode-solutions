class Solution {
public:
    int lastRemaining(int n) {
        long head = 1;
        long step = 1;
        int remain = n;
        bool left = true;

        while (remain > 1) {
            if (left || remain % 2 == 1) {
                head += step;
            }
            remain /= 2;
            step *= 2;
            left = !left;
        }
        return (int)head;
    }
};
