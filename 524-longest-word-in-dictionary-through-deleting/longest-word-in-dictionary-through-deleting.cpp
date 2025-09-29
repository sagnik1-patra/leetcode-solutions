class Solution {
public:
    bool isSubsequence(const string& word, const string& s) {
        int i = 0, j = 0;
        while (i < word.size() && j < s.size()) {
            if (word[i] == s[j]) i++;
            j++;
        }
        return i == word.size();
    }
    
    string findLongestWord(string s, vector<string>& dictionary) {
        string best = "";
        for (auto& word : dictionary) {
            if (isSubsequence(word, s)) {
                if (word.size() > best.size() || 
                   (word.size() == best.size() && word < best)) {
                    best = word;
                }
            }
        }
        return best;
    }
};