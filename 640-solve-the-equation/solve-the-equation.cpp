class Solution {
public:
    string solveEquation(string equation) {
        auto parse = [](string s) {
            int coeff = 0, constant = 0;
            if (s[0] != '-') s = "+" + s; // ensure all terms have sign
            int i = 0, n = s.size();
            while (i < n) {
                int sign = (s[i] == '+') ? 1 : -1;
                i++;
                int num = 0;
                bool hasNum = false;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                    hasNum = true;
                }
                if (i < n && s[i] == 'x') {
                    coeff += sign * (hasNum ? num : 1);
                    i++;
                } else {
                    constant += sign * num;
                }
            }
            return pair<int,int>(coeff, constant);
        };

        int eq = equation.find('=');
        string left = equation.substr(0, eq);
        string right = equation.substr(eq + 1);

        auto [lx, lc] = parse(left);
        auto [rx, rc] = parse(right);

        int x_coeff = lx - rx;
        int const_val = rc - lc;

        if (x_coeff == 0 && const_val == 0) return "Infinite solutions";
        if (x_coeff == 0) return "No solution";

        int x = const_val / x_coeff;
        return "x=" + to_string(x);
    }
};
