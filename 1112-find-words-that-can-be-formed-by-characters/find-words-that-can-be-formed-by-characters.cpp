class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> baseFreq(26, 0);
        
        // Count characters in chars
        for (char c : chars) {
            baseFreq[c - 'a']++;
        }
        
        int totalLength = 0;
        
        for (string &word : words) {
            vector<int> freq(26, 0);
            bool valid = true;
            
            // Count characters of current word
            for (char c : word) {
                freq[c - 'a']++;
                if (freq[c - 'a'] > baseFreq[c - 'a']) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                totalLength += word.length();
            }
        }
        
        return totalLength;
    }
};