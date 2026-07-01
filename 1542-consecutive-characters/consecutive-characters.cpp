class Solution {
public:
    int maxPower(string s) {
        int maxLen = 1, count = 1;
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            maxLen = max(maxLen, count);
        }
        
        return maxLen;
    }
};