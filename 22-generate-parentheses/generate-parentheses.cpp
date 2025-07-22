class Solution {
public:
    void generateCombinations(vector<string>& result, string current, int open, int close, int n) {
        if (current.length() == n * 2) {
            result.push_back(current);
            return;
        }
        if (open < n) {
            generateCombinations(result, current + "(", open + 1, close, n);
        }
        if (close < open) {
            generateCombinations(result, current + ")", open, close + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
      vector<string> result;
        generateCombinations(result, "", 0, 0, n);
        return result;  
    }
};