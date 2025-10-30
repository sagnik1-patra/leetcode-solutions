class WordFilter {
    unordered_map<string, int> lookup;

public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            string &w = words[i];
            int len = w.size();

            // Build all prefix + '#' + suffix combinations
            for (int p = 0; p <= len; ++p) {
                string prefix = w.substr(0, p);
                for (int s = 0; s <= len; ++s) {
                    string suffix = w.substr(len - s);
                    lookup[prefix + "#" + suffix] = i;
                }
            }
        }
    }

    int f(string pref, string suff) {
        string key = pref + "#" + suff;
        return lookup.count(key) ? lookup[key] : -1;
    }
};
