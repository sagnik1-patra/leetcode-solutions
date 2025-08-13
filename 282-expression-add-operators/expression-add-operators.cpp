class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string path;
        dfs(num, target, 0, 0LL, 0LL, path, res);
        return res;
    }

private:
    void dfs(const string& num, long long target, int idx,
             long long eval, long long last, string& path, vector<string>& res) {
        int n = num.size();
        if (idx == n) {
            if (eval == target) res.push_back(path);
            return;
        }

        long long cur = 0;
        int pathLen = path.size();

        for (int i = idx; i < n; ++i) {
            // avoid numbers with leading zeros
            if (i > idx && num[idx] == '0') break;

            cur = cur * 10 + (num[i] - '0');
            string token = num.substr(idx, i - idx + 1);

            if (idx == 0) {
                // first number, no operator
                path += token;
                dfs(num, target, i + 1, cur, cur, path, res);
                path.resize(pathLen);
            } else {
                // '+'
                path += '+'; path += token;
                dfs(num, target, i + 1, eval + cur, cur, path, res);
                path.resize(pathLen);

                // '-'
                path += '-'; path += token;
                dfs(num, target, i + 1, eval - cur, -cur, path, res);
                path.resize(pathLen);

                // '*': fix precedence by removing last, adding last*cur
                path += '*'; path += token;
                dfs(num, target, i + 1, eval - last + last * cur, last * cur, path, res);
                path.resize(pathLen);
            }
        }
    }
};
