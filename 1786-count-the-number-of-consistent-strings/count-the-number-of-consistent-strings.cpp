class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        int count = 0;

        for (string& word : words) {
            bool consistent = true;

            for (char c : word) {
                if (!allowedSet.count(c)) {
                    consistent = false;
                    break;
                }
            }

            if (consistent) {
                count++;
            }
        }

        return count;
    }
};