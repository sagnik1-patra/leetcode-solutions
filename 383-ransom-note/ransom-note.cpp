class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;
        int cnt[26] = {0};
        for (char c : magazine) cnt[c - 'a']++;
        for (char c : ransomNote) {
            if (--cnt[c - 'a'] < 0) return false;
        }
        return true;
    }
};
