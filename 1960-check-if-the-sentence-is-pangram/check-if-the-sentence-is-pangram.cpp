class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool seen[26] = {false};

        for (char ch : sentence) {
            seen[ch - 'a'] = true;
        }

        for (int i = 0; i < 26; i++) {
            if (!seen[i]) {
                return false;
            }
        }

        return true;
    }
};