class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size()) return false;
        
        vector<int> count(26, 0);
        
        for (int i = 0; i < s.size(); i++) {
            int shift = (t[i] - s[i] + 26) % 26;
            if (shift > 0) {
                count[shift]++;
            }
        }
        
        for (int x = 1; x < 26; x++) {
            if (count[x] > 0) {
                int maxMove = x + (count[x] - 1) * 26;
                if (maxMove > k) return false;
            }
        }
        
        return true;
    }
};