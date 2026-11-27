class Solution {
public:
    int countAsterisks(string s) {

        bool inside = false;
        int count = 0;

        for (char ch : s) {

            if (ch == '|') {
                inside = !inside;
            }
            else if (ch == '*' && !inside) {
                count++;
            }
        }

        return count;
    }
};