class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        int bestStart = 0;
        int bestLength = 0;

        for (int i = 0; i < n; i++) {
            bool lower[26] = {};
            bool upper[26] = {};

            for (int j = i; j < n; j++) {
                if (islower(s[j]))
                    lower[s[j] - 'a'] = true;
                else
                    upper[s[j] - 'A'] = true;

                bool nice = true;

                for (int k = 0; k < 26; k++) {
                    if (lower[k] != upper[k]) {
                        nice = false;
                        break;
                    }
                }

                if (nice && j - i + 1 > bestLength) {
                    bestLength = j - i + 1;
                    bestStart = i;
                }
            }
        }

        return s.substr(bestStart, bestLength);
    }
};