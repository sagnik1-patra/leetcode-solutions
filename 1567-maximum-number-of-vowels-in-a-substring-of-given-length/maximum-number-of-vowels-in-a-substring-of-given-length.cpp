class Solution {
public:
    bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    
    int maxVowels(string s, int k) {
        int count = 0, maxCount = 0;
        
        // first window
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) count++;
        }
        
        maxCount = count;
        
        // sliding window
        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i])) count++;           // add new
            if (isVowel(s[i - k])) count--;       // remove old
            
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
};