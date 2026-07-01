class Solution {
public:
    string arrangeWords(string text) {
        // Step 1: convert to lowercase
        for (char &c : text) c = tolower(c);
        
        // Step 2: split words
        vector<string> words;
        stringstream ss(text);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Step 3: stable sort by length
        stable_sort(words.begin(), words.end(),
            [](const string &a, const string &b) {
                return a.size() < b.size();
            }
        );
        
        // Step 4: join words
        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) result += " ";
        }
        
        // Step 5: capitalize first letter
        result[0] = toupper(result[0]);
        
        return result;
    }
};