class Solution {
public:
    pair<int,int> parse(string num) {
        int plusPos = num.find('+');
        int real = stoi(num.substr(0, plusPos));
        int imag = stoi(num.substr(plusPos + 1, num.size() - plusPos - 2)); // skip 'i'
        return {real, imag};
    }

    string complexNumberMultiply(string num1, string num2) {
        auto [a, b] = parse(num1);
        auto [c, d] = parse(num2);

        int real = a * c - b * d;
        int imag = a * d + b * c;

        return to_string(real) + "+" + to_string(imag) + "i";
    }
};