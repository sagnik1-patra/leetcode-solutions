class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int remL = 0, remR = 0;
        // 1) Count minimal removals needed for '(' and ')'
        for (char ch : s) {
            if (ch == '(') {
                ++remL;
            } else if (ch == ')') {
                if (remL > 0) --remL;   // match one '('
                else ++remR;            // extra ')'
            }
        }

        unordered_set<string> ansSet;   // to avoid duplicates
        string path;
        dfs(s, 0, 0, remL, remR, path, ansSet);

        return vector<string>(ansSet.begin(), ansSet.end());
    }

private:
    void dfs(const string& s, int i, int open,
             int remL, int remR, string& path,
             unordered_set<string>& out)
    {
        // Prune impossible states
        if (remL < 0 || remR < 0 || open < 0) return;

        if (i == (int)s.size()) {
            if (remL == 0 && remR == 0 && open == 0) out.insert(path);
            return;
        }

        char ch = s[i];
        int lenBefore = path.size();

        if (ch != '(' && ch != ')') {
            // Always keep letters
            path.push_back(ch);
            dfs(s, i + 1, open, remL, remR, path, out);
            path.resize(lenBefore);
            return;
        }

        // Option 1: delete this parenthesis (only if we have removals left)
        if (ch == '(' && remL > 0) {
            // Skip consecutive identical '(' deletions at same depth to reduce dup branches
            int j = i;
            while (j + 1 < (int)s.size() && s[j + 1] == '(') ++j;
            dfs(s, i + 1, open, remL - 1, remR, path, out);
        } else if (ch == ')' && remR > 0) {
            int j = i;
            while (j + 1 < (int)s.size() && s[j + 1] == ')') ++j;
            dfs(s, i + 1, open, remL, remR - 1, path, out);
        }

        // Option 2: keep this parenthesis (maintain validity)
        if (ch == '(') {
            path.push_back('(');
            dfs(s, i + 1, open + 1, remL, remR, path, out);
            path.resize(lenBefore);
        } else { // ch == ')'
            if (open > 0) { // can only keep if there's an unmatched '('
                path.push_back(')');
                dfs(s, i + 1, open - 1, remL, remR, path, out);
                path.resize(lenBefore);
            }
        }
    }
};
