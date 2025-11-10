class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int result = 0;

        for (string &w : words) {
            if (isStretchy(s, w)) result++;
        }

        return result;
    }

private:
    bool isStretchy(const string &s, const string &w) {
        int i = 0, j = 0, n = s.size(), m = w.size();

        while (i < n && j < m) {
            if (s[i] != w[j]) return false;

            // Count repeated characters in both strings
            int lenS = getRepeatLength(s, i);
            int lenW = getRepeatLength(w, j);

            // If s has fewer chars than word → cannot be stretched
            if (lenS < lenW) return false;

            // If s has more chars than word, group in s must be ≥ 3 to be stretchable
            if (lenS > lenW && lenS < 3) return false;

            i += lenS;
            j += lenW;
        }

        // Both must be fully traversed
        return i == n && j == m;
    }

    int getRepeatLength(const string &str, int start) {
        int i = start;
        while (i < str.size() && str[i] == str[start]) i++;
        return i - start;
    }
};