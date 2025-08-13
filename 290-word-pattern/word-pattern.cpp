class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        {
            istringstream iss(s);
            string w;
            while (iss >> w) words.push_back(w);
        }
        if (words.size() != pattern.size()) return false;

        unordered_map<char, string> p2w;
        unordered_map<string, char> w2p;

        for (int i = 0; i < (int)pattern.size(); ++i) {
            char p = pattern[i];
            const string& w = words[i];

            if (p2w.count(p) && p2w[p] != w) return false;
            if (w2p.count(w) && w2p[w] != p) return false;

            p2w[p] = w;
            w2p[w] = p;
        }
        return true;
    }
};
