class Solution {
public:
    unordered_map<string, vector<string>> memo;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return dfs(s, dict);
    }

    vector<string> dfs(string s, unordered_set<string>& dict) {
        if (memo.count(s)) return memo[s];
        vector<string> result;

        if (dict.count(s)) {
            result.push_back(s);
        }

        for (int i = 1; i < s.length(); ++i) {
            string prefix = s.substr(0, i);
            string suffix = s.substr(i);

            if (dict.count(prefix)) {
                vector<string> suffixWays = dfs(suffix, dict);
                for (string& sentence : suffixWays) {
                    result.push_back(prefix + " " + sentence);
                }
            }
        }

        memo[s] = result;
        return result;
    }
};
