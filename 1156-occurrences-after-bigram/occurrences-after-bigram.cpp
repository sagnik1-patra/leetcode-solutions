class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        string word;

        // Split text into words
        for (char c : text) {
            if (c == ' ') {
                words.push_back(word);
                word.clear();
            } else {
                word.push_back(c);
            }
        }
        words.push_back(word); // last word

        vector<string> result;

        // Check occurrences of "first second third"
        for (int i = 0; i + 2 < words.size(); i++) {
            if (words[i] == first && words[i + 1] == second) {
                result.push_back(words[i + 2]);
            }
        }

        return result;
    }
};
