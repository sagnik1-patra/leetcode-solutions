class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> first(26, -1);
        int ans = -1;
        
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            
            if (first[c] == -1) {
                first[c] = i;
            } else {
                ans = max(ans, i - first[c] - 1);
            }
        }
        
        return ans;
    }
};