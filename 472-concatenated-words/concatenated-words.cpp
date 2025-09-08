class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // Sort by length so we only build longer words from shorter ones
        sort(words.begin(), words.end(),
             [](const string& a, const string& b){ return a.size() < b.size(); });

        unordered_set<string> dict;
        vector<string> ans;

        for (const string& w : words) {
            if (!w.empty() && canForm(w, dict)) {
                ans.push_back(w);
            }
            dict.insert(w); // make this word available for building longer ones
        }
        return ans;
    }

private:
    // Can s be formed by concatenating >= 2 words from dict?
    static bool canForm(const string& s, const unordered_set<string>& dict) {
        if (dict.empty()) return false; // nothing to build from
        int n = (int)s.size();
        vector<char> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (!dp[j]) continue;
                if (dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        // Must be at least two words: ensure we didn't use the whole word as a single piece.
        // Because dict only has strictly shorter words (we insert after checking),
        // dp[n] implies >= 2 pieces automatically. So just return dp[n].
        return dp[n];
    }
};