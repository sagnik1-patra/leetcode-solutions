class Solution {
public:
    int maxRepOpt1(string text) {
        vector<int> freq(26, 0);
        for (char c : text)
            freq[c - 'a']++;
        
        int n = text.size();
        int ans = 0;
        
        for (int ch = 0; ch < 26; ch++) {
            char target = 'a' + ch;
            
            int left = 0, countTarget = 0;
            
            for (int right = 0; right < n; right++) {
                if (text[right] == target)
                    countTarget++;
                
                // If more than 1 non-target character in window
                while ((right - left + 1) - countTarget > 1) {
                    if (text[left] == target)
                        countTarget--;
                    left++;
                }
                
                // Window length cannot exceed total frequency of target
                ans = max(ans, min(freq[ch], right - left + 1));
            }
        }
        
        return ans;
    }
};