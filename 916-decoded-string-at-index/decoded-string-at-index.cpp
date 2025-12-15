class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long len = 0;

        // Step 1: compute total decoded length
        for (char c : s) {
            if (isdigit(c)) {
                len *= (c - '0');
            } else {
                len++;
            }
        }

        // Step 2: work backwards
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];

            if (isdigit(c)) {
                long long d = c - '0';
                len /= d;
                k %= len;
                if (k == 0) k = len;
            } else {
                if (k == len) {
                    return string(1, c);
                }
                len--;
            }
        }

        return "";
    }
};
