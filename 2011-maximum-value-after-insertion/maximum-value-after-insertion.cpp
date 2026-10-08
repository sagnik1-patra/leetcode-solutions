
class Solution {
public:
    string maxValue(string n, int x) {
        char digit = x + '0';

        if (n[0] == '-') {
            // Negative number
            for (int i = 1; i < n.size(); i++) {
                if (n[i] > digit) {
                    n.insert(i, 1, digit);
                    return n;
                }
            }
        } else {
            // Positive number
            for (int i = 0; i < n.size(); i++) {
                if (n[i] < digit) {
                    n.insert(i, 1, digit);
                    return n;
                }
            }
        }

        // Insert at the end if no position found
        n.push_back(digit);

        return n;
    }
};
