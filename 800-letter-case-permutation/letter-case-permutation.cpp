class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        dfs(s, 0, result);
        return result;
    }

private:
    void dfs(string& s, int i, vector<string>& result) {
        if (i == s.size()) {
            result.push_back(s);
            return;
        }

        if (isalpha(s[i])) {
            // Lowercase branch
            s[i] = tolower(s[i]);
            dfs(s, i + 1, result);

            // Uppercase branch
            s[i] = toupper(s[i]);
            dfs(s, i + 1, result);
        } else {
            // Digit → move on
            dfs(s, i + 1, result);
        }
    }
};
