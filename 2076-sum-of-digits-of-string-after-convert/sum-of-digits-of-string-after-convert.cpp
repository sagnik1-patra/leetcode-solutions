
class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";

        for (char c : s) {
            int value = c - 'a' + 1;
            num += to_string(value);
        }

        int sum = 0;

        while (k--) {
            sum = 0;

            for (char c : num) {
                sum += c - '0';
            }

            num = to_string(sum);
        }

        return sum;
    }
};
