class Solution {
public:
    string reformatNumber(string number) {
        string digits = "";

        // Remove spaces and dashes
        for (char c : number) {
            if (isdigit(c)) {
                digits += c;
            }
        }

        string ans = "";
        int i = 0;
        int n = digits.size();

        // Create blocks of 3 while more than 4 digits remain
        while (n - i > 4) {
            if (!ans.empty())
                ans += "-";

            ans += digits.substr(i, 3);
            i += 3;
        }

        int remaining = n - i;

        if (!ans.empty())
            ans += "-";

        // Handle remaining digits
        if (remaining == 4) {
            ans += digits.substr(i, 2);
            ans += "-";
            ans += digits.substr(i + 2, 2);
        } 
        else {
            // Remaining will be 2 or 3
            ans += digits.substr(i, remaining);
        }

        return ans;
    }
};