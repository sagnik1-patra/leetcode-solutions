class Solution {
public:
    using Term = vector<string>;   // sorted list of variables
    using Poly = map<Term, int>;   // term → coefficient

    vector<string> basicCalculatorIV(string expression,
                                     vector<string>& evalvars,
                                     vector<int>& evalints) {
        unordered_map<string, int> val;
        for (int i = 0; i < evalvars.size(); ++i)
            val[evalvars[i]] = evalints[i];

        int i = 0;
        Poly poly = parse(expression, i, val);
        return toList(poly);
    }

private:
    // Parse an expression recursively
    Poly parse(const string& s, int& i, unordered_map<string, int>& val) {
        vector<Poly> terms;
        vector<char> ops = {'+'};

        while (i < s.size() && s[i] != ')') {
            if (s[i] == ' ') { i++; continue; }

            if (s[i] == '(') {
                ++i;
                Poly sub = parse(s, i, val);
                ++i; // skip ')'
                terms.push_back(sub);
            } 
            else if (isalpha(s[i])) {
                string var;
                while (i < s.size() && isalpha(s[i])) var += s[i++];
                if (val.count(var)) {
                    terms.push_back({{{}, val[var]}});
                } else {
                    terms.push_back({{{var}, 1}});
                }
            } 
            else if (isdigit(s[i])) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) num = num * 10 + (s[i++] - '0');
                terms.push_back({{{}, num}});
            } 
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                ops.push_back(s[i++]);
            }
        }

        return eval(terms, ops);
    }

    // Combine terms according to operators
    Poly eval(vector<Poly>& terms, vector<char>& ops) {
        vector<Poly> muls;
        for (int i = 0; i < ops.size(); ++i) {
            if (ops[i] == '*') {
                Poly a = muls.back(); muls.pop_back();
                muls.push_back(multiply(a, terms[i]));
            } else if (ops[i] == '-') {
                terms[i] = negatePoly(terms[i]);
                muls.push_back(terms[i]);
            } else {
                muls.push_back(terms[i]);
            }
        }

        Poly res;
        for (auto& p : muls) res = add(res, p);
        return res;
    }

    // Polynomial addition
    Poly add(Poly& a, Poly& b) {
        Poly res = a;
        for (auto& [term, coeff] : b)
            res[term] += coeff;
        for (auto it = res.begin(); it != res.end();)
            if (it->second == 0) it = res.erase(it);
            else ++it;
        return res;
    }

    // Negation
    Poly negatePoly(Poly& a) {
        Poly res = a;
        for (auto& [term, coeff] : res)
            res[term] = -coeff;
        return res;
    }

    // Multiplication
    Poly multiply(Poly& a, Poly& b) {
        Poly res;
        for (auto& [ta, ca] : a)
            for (auto& [tb, cb] : b) {
                Term term = ta;
                term.insert(term.end(), tb.begin(), tb.end());
                sort(term.begin(), term.end());
                res[term] += ca * cb;
            }
        for (auto it = res.begin(); it != res.end();)
            if (it->second == 0) it = res.erase(it);
            else ++it;
        return res;
    }

    // Convert polynomial to required string list
    vector<string> toList(Poly& p) {
        vector<pair<Term, int>> v(p.begin(), p.end());
        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            if (a.first.size() != b.first.size())
                return a.first.size() > b.first.size();
            return a.first < b.first;
        });

        vector<string> res;
        for (auto& [term, coeff] : v) {
            string t = to_string(coeff);
            for (auto& var : term) t += "*" + var;
            res.push_back(t);
        }
        return res;
    }
};
