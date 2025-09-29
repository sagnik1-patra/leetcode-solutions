class Solution {
public:
    bool detectCapitalUse(string word) {
        // Case 1: all uppercase
        if (all_of(word.begin(), word.end(), ::isupper)) return true;

        // Case 2: all lowercase
        if (all_of(word.begin(), word.end(), ::islower)) return true;

        // Case 3: first letter uppercase, rest lowercase
        if (isupper(word[0]) && 
            all_of(word.begin() + 1, word.end(), ::islower)) return true;

        return false;
    }
};