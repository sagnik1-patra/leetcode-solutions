class Solution {
public:
    string truncateSentence(string s, int k) {
        int spaces = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                spaces++;

                if (spaces == k) {
                    return s.substr(0, i);
                }
            }
        }

        return s;
    }
};