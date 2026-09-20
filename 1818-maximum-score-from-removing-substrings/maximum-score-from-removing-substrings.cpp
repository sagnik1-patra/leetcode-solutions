class Solution {
public:
    int totalScore = 0;

    string removePair(string s, char first, char second, int points) {
        string st;

        for (char c : s) {
            if (!st.empty() && st.back() == first && c == second) {
                st.pop_back();
                totalScore += points;
            } else {
                st.push_back(c);
            }
        }

        return st;
    }

    int maximumGain(string s, int x, int y) {
        totalScore = 0;

        // Always remove the higher-value substring first
        if (x >= y) {
            s = removePair(s, 'a', 'b', x);
            s = removePair(s, 'b', 'a', y);
        } else {
            s = removePair(s, 'b', 'a', y);
            s = removePair(s, 'a', 'b', x);
        }

        return totalScore;
    }
};