class Solution {
public:
    string sortString(string s) {
        vector<int> freq(26, 0);
        
        // count frequency
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        string res = "";
        
        while (res.size() < s.size()) {
            
            // Step 1: smallest → largest
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0) {
                    res += (char)(i + 'a');
                    freq[i]--;
                }
            }
            
            // Step 2: largest → smallest
            for (int i = 25; i >= 0; i--) {
                if (freq[i] > 0) {
                    res += (char)(i + 'a');
                    freq[i]--;
                }
            }
        }
        
        return res;
    }
};