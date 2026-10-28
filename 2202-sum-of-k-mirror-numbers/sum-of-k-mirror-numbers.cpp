class Solution {
public:
    bool isPalindrome(long long num, int k) {
        vector<int> digits;

        while (num > 0) {
            digits.push_back(num % k);
            num /= k;
        }

        int i = 0;
        int j = digits.size() - 1;

        while (i < j) {
            if (digits[i] != digits[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;

        for (int len = 1; n > 0; len++) {

            int half = (len + 1) / 2;

            long long start = 1;
            for (int i = 1; i < half; i++) {
                start *= 10;
            }

            long long end = start * 10;

            for (long long i = start; i < end && n > 0; i++) {

                long long num = i;
                long long temp = (len % 2 == 0) ? i : i / 10;

                while (temp > 0) {
                    num = num * 10 + temp % 10;
                    temp /= 10;
                }

                if (isPalindrome(num, k)) {
                    sum += num;
                    n--;
                }
            }
        }

        return sum;
    }
};