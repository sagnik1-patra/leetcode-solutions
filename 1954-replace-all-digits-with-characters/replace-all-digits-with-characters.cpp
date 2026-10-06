class Solution {
public:
    char shift(char c, int x) {
        return c + x;
    }

    string replaceDigits(string s) {

        for (int i = 1; i < s.size(); i += 2) {

            int x = s[i] - '0';

            s[i] = shift(s[i - 1], x);
        }

        return s;
    }
};