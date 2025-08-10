class Solution {
public:
    int calculate(string s) {
        stack<int> st; // to store previous results and signs
        int result = 0; // current calculated result
        int num = 0;    // current number
        int sign = 1;   // current sign (+1 or -1)
        
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); // build number
            } 
            else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } 
            else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } 
            else if (c == '(') {
                // Push current state
                st.push(result);
                st.push(sign);
                // Reset for new sub-expression
                result = 0;
                sign = 1;
            } 
            else if (c == ')') {
                result += sign * num;
                num = 0;
                // Apply sign before '('
                result *= st.top(); st.pop();
                // Add previous result before '('
                result += st.top(); st.pop();
            }
        }
        result += sign * num; // add last number
        return result;
    }
};
