class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        // If already computed for this substring
        if (memo.count(expression)) 
            return memo[expression];

        vector<int> results;
        bool isNumber = true;

        // Split expression at each operator
        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                isNumber = false;

                // Divide into left and right parts
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                // Combine results
                for (int a : left) {
                    for (int b : right) {
                        if (c == '+') results.push_back(a + b);
                        else if (c == '-') results.push_back(a - b);
                        else if (c == '*') results.push_back(a * b);
                    }
                }
            }
        }

        // Base case: expression is a number
        if (isNumber) {
            results.push_back(stoi(expression));
        }

        // Store in memo and return
        memo[expression] = results;
        return results;
    }
};
