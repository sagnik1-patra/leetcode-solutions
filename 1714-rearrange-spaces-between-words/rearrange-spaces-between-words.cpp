class Solution {
public:
    string reorderSpaces(string text) {
        int spaceCount = 0;
        
        // count spaces
        for (char c : text) {
            if (c == ' ') spaceCount++;
        }
        
        // extract words
        vector<string> words;
        string word = "";
        for (char c : text) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) words.push_back(word);
        
        int n = words.size();
        
        // if only one word
        if (n == 1) {
            return words[0] + string(spaceCount, ' ');
        }
        
        int spacesBetween = spaceCount / (n - 1);
        int extraSpaces = spaceCount % (n - 1);
        
        string gap(spacesBetween, ' ');
        string result = "";
        
        for (int i = 0; i < n; i++) {
            result += words[i];
            if (i < n - 1) result += gap;
        }
        
        result += string(extraSpaces, ' ');
        
        return result;
    }
};