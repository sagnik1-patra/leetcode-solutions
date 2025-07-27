class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> current;
        backtrack(s, 0, current, result);
        return result;
    }

private:
    void backtrack(const string& s, int start, vector<string>& current, vector<string>& result) {
        if (current.size() == 4) {
            if (start == s.size()) {
                result.push_back(current[0] + '.' + current[1] + '.' + current[2] + '.' + current[3]);
            }
            return;
        }

        for (int len = 1; len <= 3; ++len) {
            if (start + len > s.size()) break;

            string segment = s.substr(start, len);
            if (isValid(segment)) {
                current.push_back(segment);
                backtrack(s, start + len, current, result);
                current.pop_back(); // backtrack
            }
        }
    }

    bool isValid(const string& segment) {
        if (segment.empty() || (segment.size() > 1 && segment[0] == '0')) return false;
        int val = stoi(segment);
        return val >= 0 && val <= 255;
    }
};
