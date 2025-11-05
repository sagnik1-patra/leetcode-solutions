class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // Map each character to the list of indices where it appears in s
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); ++i) {
            pos[s[i] - 'a'].push_back(i);
        }

        int count = 0;

        // Check each word if it's a subsequence
        for (string &w : words) {
            int prev = -1;
            bool isSubseq = true;

            for (char c : w) {
                auto &indices = pos[c - 'a'];
                // If no such character in s
                if (indices.empty()) {
                    isSubseq = false;
                    break;
                }

                // Binary search for next position greater than prev
                auto it = upper_bound(indices.begin(), indices.end(), prev);
                if (it == indices.end()) {
                    isSubseq = false;
                    break;
                }

                prev = *it;
            }

            if (isSubseq) count++;
        }

        return count;
    }
};