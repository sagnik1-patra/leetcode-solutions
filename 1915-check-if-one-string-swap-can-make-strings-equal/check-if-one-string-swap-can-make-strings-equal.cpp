class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diff;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }

        // Already equal
        if (diff.size() == 0)
            return true;

        // One swap can only fix exactly 2 differences
        if (diff.size() != 2)
            return false;

        int i = diff[0];
        int j = diff[1];

        return s1[i] == s2[j] && s1[j] == s2[i];
    }
};