class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;
        mp[0] = -1;  // base case
        
        int mask = 0;
        int ans = 0;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            
            // toggle bits for vowels
            if (c == 'a') mask ^= (1 << 0);
            else if (c == 'e') mask ^= (1 << 1);
            else if (c == 'i') mask ^= (1 << 2);
            else if (c == 'o') mask ^= (1 << 3);
            else if (c == 'u') mask ^= (1 << 4);
            
            // seen before → valid substring
            if (mp.count(mask)) {
                ans = max(ans, i - mp[mask]);
            } else {
                mp[mask] = i;
            }
        }
        
        return ans;
    }
};