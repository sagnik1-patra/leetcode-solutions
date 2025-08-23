class Solution {
public:
    string originalDigits(string s) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;

        int d[10] = {0};

        // unique letters
        d[0] = cnt['z' - 'a']; // zero
        d[2] = cnt['w' - 'a']; // two
        d[4] = cnt['u' - 'a']; // four
        d[6] = cnt['x' - 'a']; // six
        d[8] = cnt['g' - 'a']; // eight

        // dependent ones
        d[3] = cnt['h' - 'a'] - d[8];                 // three
        d[5] = cnt['f' - 'a'] - d[4];                 // five
        d[7] = cnt['s' - 'a'] - d[6];                 // seven
        d[1] = cnt['o' - 'a'] - d[0] - d[2] - d[4];   // one
        d[9] = cnt['i' - 'a'] - d[5] - d[6] - d[8];   // nine

        string ans;
        for (int digit = 0; digit <= 9; ++digit) {
            ans.append(d[digit], char('0' + digit));
        }
        return ans;
    }
};
