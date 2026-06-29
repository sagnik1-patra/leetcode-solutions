class Solution {
public:
    string reformat(string s) {
        string letters = "";
        string digits = "";

        for (char ch : s) {
            if (isdigit(ch)) {
                digits += ch;
            } else {
                letters += ch;
            }
        }

        if (abs((int)letters.size() - (int)digits.size()) > 1) {
            return "";
        }

        string ans = "";

        bool useLetter = letters.size() > digits.size();

        int i = 0, j = 0;

        while (i < letters.size() || j < digits.size()) {
            if (useLetter) {
                ans += letters[i++];
            } else {
                ans += digits[j++];
            }

            useLetter = !useLetter;
        }

        return ans;
    }
};