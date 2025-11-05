class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;

        for (int i = 1; i <= n; i++) {
            int num = i;
            bool valid = true, diff = false;

            while (num > 0) {
                int d = num % 10;
                num /= 10;

                // Invalid digits
                if (d == 3 || d == 4 || d == 7) {
                    valid = false;
                    break;
                }

                // Digits that change upon rotation
                if (d == 2 || d == 5 || d == 6 || d == 9) {
                    diff = true;
                }
            }

            if (valid && diff) count++;
        }

        return count;
    }
};