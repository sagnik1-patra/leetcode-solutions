class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        vector<int> count(26, 0); // for lowercase letters
        
        for (char c : s) count[c - 'a']++;
        for (char c : t) count[c - 'a']--;
        
        for (int val : count) {
            if (val != 0) return false;
        }
        return true;
    }
};