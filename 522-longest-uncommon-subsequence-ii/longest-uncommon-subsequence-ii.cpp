class Solution {
public:
    // Check if s is a subsequence of t
    bool isSubsequence(const string &s, const string &t) {
        int i = 0, j = 0;
        while (i < (int)s.size() && j < (int)t.size()) {
            if (s[i] == t[j]) i++;
            j++;
        }
        return i == (int)s.size();
    }

    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int ans = -1;

        for (int i = 0; i < n; i++) {
            bool uncommon = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j])) {
                    uncommon = false;
                    break;
                }
            }
            if (uncommon) {
                ans = max(ans, (int)strs[i].size());
            }
        }
        return ans;
    }
};