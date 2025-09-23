class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool neg = num < 0;
        long long n = llabs((long long)num);
        string res;
        while (n > 0) {
            res.push_back('0' + (n % 7));
            n /= 7;
        }
        if (neg) res.push_back('-');
        reverse(res.begin(), res.end());
        return res;
    }
};
