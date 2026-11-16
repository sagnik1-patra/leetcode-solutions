
class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0)
            return 0;

        bool negative = num < 0;

        string s = to_string(abs(num));

        if (negative) {
            sort(s.begin(), s.end(), greater<char>());
            return -stoll(s);
        }

        sort(s.begin(), s.end());

        // Move first non-zero digit to the front
        int i = 0;
        while (s[i] == '0')
            i++;

        swap(s[0], s[i]);

        return stoll(s);
    }
};
