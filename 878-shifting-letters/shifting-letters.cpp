class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long total = 0;
        int n = s.size();

        // compute cumulative shifts from right to left
        for (int i = n - 1; i >= 0; i--) {
            total = (total + shifts[i]) % 26;

            s[i] = char(((s[i] - 'a') + total) % 26 + 'a');
        }

        return s;
    }
};
