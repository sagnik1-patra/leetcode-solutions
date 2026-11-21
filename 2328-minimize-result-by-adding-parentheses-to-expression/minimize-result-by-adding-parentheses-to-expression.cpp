
class Solution {
public:
    string minimizeResult(string expression) {
        int plus = expression.find('+');
        int n = expression.size();

        int mini = INT_MAX;
        string ans = "";

        for (int i = 0; i < plus; i++) {
            for (int j = plus + 2; j <= n; j++) {

                string left = expression.substr(0, i);
                string num1 = expression.substr(i, plus - i);
                string num2 = expression.substr(plus + 1, j - plus - 1);
                string right = expression.substr(j);

                int a = left.empty() ? 1 : stoi(left);
                int b = stoi(num1);
                int c = stoi(num2);
                int d = right.empty() ? 1 : stoi(right);

                int value = a * (b + c) * d;

                if (value < mini) {
                    mini = value;

                    ans = left + "(" + num1 + "+" +
                          num2 + ")" + right;
                }
            }
        }

        return ans;
    }
};
