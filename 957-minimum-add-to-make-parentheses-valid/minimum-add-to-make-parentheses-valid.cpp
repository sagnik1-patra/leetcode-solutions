class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int moves = 0;

        for (char c : s) {
            if (c == '(') {
                balance++;
            } else { // ')'
                if (balance > 0) {
                    balance--;
                } else {
                    moves++; // insert '('
                }
            }
        }

        // remaining '(' need ')'
        return moves + balance;
    }
};
