class Solution {
public:
    string s;
    int i = 0;

    // Cartesian product of two sets
    set<string> multiply(const set<string>& a, const set<string>& b) {
        set<string> res;
        for (auto& x : a) {
            for (auto& y : b) {
                res.insert(x + y);
            }
        }
        return res;
    }

    // Parse expression
    set<string> parse() {
        set<string> res = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> cur;

            if (s[i] == '{') {
                i++;  // skip '{'
                set<string> temp;
                while (true) {
                    auto part = parse();
                    temp.insert(part.begin(), part.end());
                    if (s[i] == '}') break;
                    i++; // skip ','
                }
                i++; // skip '}'
                cur = temp;
            } else {
                cur.insert(string(1, s[i++]));
            }

            res = multiply(res, cur);
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> result;
        while (i < s.size()) {
            auto part = parse();
            result.insert(part.begin(), part.end());
            if (i < s.size() && s[i] == ',') i++;
        }

        return vector<string>(result.begin(), result.end());
    }
};
