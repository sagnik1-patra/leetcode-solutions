class Solution {
public:
    
    int getFreq(string &s) {
        char smallest = 'z';
        int count = 0;
        
        for (char c : s) {
            if (c < smallest) {
                smallest = c;
                count = 1;
            } else if (c == smallest) {
                count++;
            }
        }
        return count;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        vector<int> wordFreq;
        
        // Compute frequency for words
        for (string &w : words) {
            wordFreq.push_back(getFreq(w));
        }
        
        sort(wordFreq.begin(), wordFreq.end());
        
        vector<int> result;
        
        for (string &q : queries) {
            int qFreq = getFreq(q);
            
            // Count how many word frequencies > qFreq
            int count = wordFreq.end() - upper_bound(wordFreq.begin(), wordFreq.end(), qFreq);
            
            result.push_back(count);
        }
        
        return result;
    }
};