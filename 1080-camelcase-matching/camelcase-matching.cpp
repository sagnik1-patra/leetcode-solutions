class Solution {
public:
    bool matches(string& query, string& pattern) {
        int j = 0; // pointer for pattern

        for (char c : query) {
            if (j < pattern.size() && c == pattern[j]) {
                j++;
            } else if (isupper(c)) {
                return false;
            }
        }

        return j == pattern.size();
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        for (string& q : queries) {
            result.push_back(matches(q, pattern));
        }
        return result;
    }
};
