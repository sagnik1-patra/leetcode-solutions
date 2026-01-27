class Solution {
public:
    string alphabetBoardPath(string target) {
        int r = 0, c = 0; // start at 'a'
        string ans;

        for (char ch : target) {
            int nr = (ch - 'a') / 5;
            int nc = (ch - 'a') % 5;

            // Special handling: move UP/LEFT first when leaving 'z'
            while (r > nr) { ans += 'U'; r--; }
            while (c > nc) { ans += 'L'; c--; }
            while (r < nr) { ans += 'D'; r++; }
            while (c < nc) { ans += 'R'; c++; }

            ans += '!';
        }
        return ans;
    }
};
