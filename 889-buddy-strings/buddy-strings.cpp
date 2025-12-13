class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        // Case 1: strings are equal
        if (s == goal) {
            vector<int> freq(26, 0);
            for (char c : s) {
                if (++freq[c - 'a'] > 1)
                    return true;  // duplicate exists
            }
            return false;
        }

        // Case 2: strings differ
        vector<int> diff;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i])
                diff.push_back(i);
        }

        if (diff.size() != 2)
            return false;

        return s[diff[0]] == goal[diff[1]] &&
               s[diff[1]] == goal[diff[0]];
    }
};
