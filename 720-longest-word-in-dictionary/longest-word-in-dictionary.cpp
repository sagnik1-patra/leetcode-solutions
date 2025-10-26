class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> built;
        string result = "";

        for (const string& w : words) {
            if (w.size() == 1 || built.count(w.substr(0, w.size() - 1))) {
                built.insert(w);
                if (w.size() > result.size())
                    result = w;
            }
        }

        return result;
    }
};
