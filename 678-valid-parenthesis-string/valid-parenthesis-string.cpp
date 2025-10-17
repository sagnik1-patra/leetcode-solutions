class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;   // one more unmatched '('
                high++;
            } else if (c == ')') {
                if (low > 0) low--;  // use one '(' if possible
                high--;              // must close one possible '('
            } else { // c == '*'
                if (low > 0) low--;  // '*' can be '(' or ')'
                high++;              // or '('
            }

            // If high < 0 → too many ')' encountered
            if (high < 0) return false;
        }

        // low == 0 means all '(' can be balanced
        return low == 0;
    }
};
