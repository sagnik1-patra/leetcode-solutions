class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        int last = -1;

        for (int i = 0; i < n; i++) {
            if (number[i] == digit) {
                last = i;

                if (i + 1 < n && number[i + 1] > digit) {
                    number.erase(i, 1);
                    return number;
                }
            }
        }

        number.erase(last, 1);
        return number;
    }
};