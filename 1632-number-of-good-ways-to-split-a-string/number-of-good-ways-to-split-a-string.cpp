class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        
        vector<int> prefix(n), suffix(n);
        vector<int> freq(26, 0);
        
        // prefix distinct count
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (freq[s[i] - 'a'] == 0) count++;
            freq[s[i] - 'a']++;
            prefix[i] = count;
        }
        
        // reset freq
        fill(freq.begin(), freq.end(), 0);
        count = 0;
        
        // suffix distinct count
        for (int i = n - 1; i >= 0; i--) {
            if (freq[s[i] - 'a'] == 0) count++;
            freq[s[i] - 'a']++;
            suffix[i] = count;
        }
        
        // count good splits
        int result = 0;
        for (int i = 0; i < n - 1; i++) {
            if (prefix[i] == suffix[i + 1]) {
                result++;
            }
        }
        
        return result;
    }
};