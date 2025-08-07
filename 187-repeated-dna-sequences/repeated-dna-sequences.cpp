class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> seen;
        vector<string> result;

        if (s.length() < 10) return result;

        for (int i = 0; i <= s.length() - 10; ++i) {
            string sub = s.substr(i, 10);
            seen[sub]++;
            if (seen[sub] == 2) {
                result.push_back(sub);
            }
        }

        return result;
    }
};
