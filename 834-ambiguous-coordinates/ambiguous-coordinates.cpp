class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> res;
        string digits = s.substr(1, s.size() - 2); // remove '(' and ')'

        // Try all possible splits
        for (int i = 1; i < digits.size(); i++) {
            string left = digits.substr(0, i);
            string right = digits.substr(i);

            vector<string> leftParts = generateValidNumbers(left);
            vector<string> rightParts = generateValidNumbers(right);

            for (auto &l : leftParts)
                for (auto &r : rightParts)
                    res.push_back("(" + l + ", " + r + ")");
        }

        return res;
    }

private:
    vector<string> generateValidNumbers(const string &s) {
        vector<string> result;
        int n = s.size();

        // Case 1: integer (no decimal)
        if (isValidInteger(s)) result.push_back(s);

        // Case 2: add decimal point
        for (int i = 1; i < n; i++) {
            string left = s.substr(0, i), right = s.substr(i);
            if (isValidInteger(left) && isValidFraction(right))
                result.push_back(left + "." + right);
        }

        return result;
    }

    bool isValidInteger(const string &s) {
        // "0" is valid, but no leading zeros allowed otherwise
        return s == "0" || s[0] != '0';
    }

    bool isValidFraction(const string &s) {
        // No trailing zeros allowed after decimal
        return s.back() != '0';
    }
};