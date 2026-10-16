
class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool started = false;

        for (int i = 0; i < num.size(); i++) {
            int digit = num[i] - '0';
            int newDigit = change[digit];

            if (newDigit > digit) {
                num[i] = newDigit + '0';
                started = true;
            }
            else if (started && newDigit < digit) {
                break;
            }
        }

        return num;
    }
};
