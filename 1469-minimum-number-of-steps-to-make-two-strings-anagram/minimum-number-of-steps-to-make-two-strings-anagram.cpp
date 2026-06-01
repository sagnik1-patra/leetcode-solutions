class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freqS(26, 0), freqT(26, 0);
        
        // count frequencies
        for (char c : s) freqS[c - 'a']++;
        for (char c : t) freqT[c - 'a']++;
        
        int steps = 0;
        
        // count extra characters in t
        for (int i = 0; i < 26; i++) {
            if (freqT[i] > freqS[i]) {
                steps += freqT[i] - freqS[i];
            }
        }
        
        return steps;
    }
};