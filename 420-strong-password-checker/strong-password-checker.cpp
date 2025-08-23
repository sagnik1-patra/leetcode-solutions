class Solution {
public:
    int strongPasswordChecker(string s) {
        int n = s.size();

        // 1) count missing types
        bool hasLower = false, hasUpper = false, hasDigit = false;
        for (char c : s) {
            if (c >= 'a' && c <= 'z') hasLower = true;
            else if (c >= 'A' && c <= 'Z') hasUpper = true;
            else if (c >= '0' && c <= '9') hasDigit = true;
        }
        int missing = (!hasLower) + (!hasUpper) + (!hasDigit);

        // 2) collect runs (lengths of repeating chars)
        vector<int> runs;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) ++j;
            int L = j - i;
            if (L >= 3) runs.push_back(L);
            i = j;
        }

        if (n < 6) {
            // Need insertions; inserts also help fix missing types and triples
            return max(missing, 6 - n);
        }

        // compute base replacements from runs
        long long replacements = 0;
        int cntMod[3] = {0, 0, 0};
        for (int L : runs) {
            replacements += L / 3;
            cntMod[L % 3]++;
        }

        if (n <= 20) {
            // Only replacements vs missing types
            return (int)max<long long>(missing, replacements);
        }

        // n > 20: deletions to reduce length first, and use them to reduce replacements
        int del = n - 20;

        // Use deletions on runs where it helps most:
        // For L%3==0, 1 deletion cuts 1 replacement
        int use = min(cntMod[0], del);
        replacements -= use;
        del -= use;

        // For L%3==1, 2 deletions cut 1 replacement
        use = min(cntMod[1], del / 2);
        replacements -= use;
        del -= use * 2;

        // For the rest (L%3==2 or any), every 3 deletions cut 1 replacement
        if (del > 0) {
            long long cut = del / 3;
            replacements -= cut;
            // del -= cut * 3; // not needed further
        }

        // After deletions, still need fixes for missing types and remaining triple replacements
        long long steps = (n - 20) + max<long long>(missing, replacements);
        return (int)steps;
    }
};
