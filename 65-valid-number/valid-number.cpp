class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.length();

        // Skip leading whitespaces
        while (i < n && s[i] == ' ') i++;
        
        // Optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;

        bool isNumeric = false, isDecimal = false;

        // Integer or decimal part before e
        while (i < n && isdigit(s[i])) {
            i++;
            isNumeric = true;
        }

        // Decimal point
        if (i < n && s[i] == '.') {
            i++;
            // Fractional part after decimal point
            while (i < n && isdigit(s[i])) {
                i++;
                isNumeric = true;
                isDecimal = true;
            }
        }

        // Exponential part
        if (isNumeric && i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            isNumeric = false; // Need at least one digit after e

            // Optional sign after e
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;

            while (i < n && isdigit(s[i])) {
                i++;
                isNumeric = true;
            }
        }

        // Skip trailing whitespaces
        while (i < n && s[i] == ' ') i++;

        // Return true only if all characters are processed and it's numeric
        return isNumeric && i == n;
    }
};
