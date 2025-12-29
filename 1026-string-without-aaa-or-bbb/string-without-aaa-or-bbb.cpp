class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s = "";

        while (a > 0 || b > 0) {
            int n = s.size();

            // If last two are 'aa', must place 'b'
            if (n >= 2 && s[n - 1] == 'a' && s[n - 2] == 'a') {
                s.push_back('b');
                b--;
            }
            // If last two are 'bb', must place 'a'
            else if (n >= 2 && s[n - 1] == 'b' && s[n - 2] == 'b') {
                s.push_back('a');
                a--;
            }
            // Otherwise, place the one with larger count
            else if (a >= b && a > 0) {
                s.push_back('a');
                a--;
            } else {
                s.push_back('b');
                b--;
            }
        }

        return s;
    }
};
