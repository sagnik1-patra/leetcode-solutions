class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<int, int> firstSeen;
        firstSeen[0] = -1;
        
        int mask = 0;
        int result = 0;
        
        for (int i = 0; i < s.size(); i++) {
            int digit = s[i] - '0';
            mask ^= (1 << digit);
            
            // case 1: same mask
            if (firstSeen.count(mask)) {
                result = max(result, i - firstSeen[mask]);
            } else {
                firstSeen[mask] = i;
            }
            
            // case 2: one bit difference
            for (int d = 0; d < 10; d++) {
                int newMask = mask ^ (1 << d);
                if (firstSeen.count(newMask)) {
                    result = max(result, i - firstSeen[newMask]);
                }
            }
        }
        
        return result;
    }
};