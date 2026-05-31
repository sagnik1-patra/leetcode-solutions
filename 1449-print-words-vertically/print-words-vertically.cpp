class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        
        // Step 1: split words
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Step 2: find max length
        int maxLen = 0;
        for (auto &w : words) {
            maxLen = max(maxLen, (int)w.size());
        }
        
        vector<string> result;
        
        // Step 3: build vertically
        for (int i = 0; i < maxLen; i++) {
            string temp = "";
            
            for (auto &w : words) {
                if (i < w.size()) {
                    temp += w[i];
                } else {
                    temp += ' ';
                }
            }
            
            // Step 4: remove trailing spaces
            while (!temp.empty() && temp.back() == ' ') {
                temp.pop_back();
            }
            
            result.push_back(temp);
        }
        
        return result;
    }
};