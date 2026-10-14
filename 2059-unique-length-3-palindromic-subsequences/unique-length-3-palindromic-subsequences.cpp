
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;

        for (char ch = 'a'; ch <= 'z'; ch++) {
            int left = s.find(ch);
            int right = s.rfind(ch);

            if (left == string::npos || left >= right)
                continue;

            unordered_set<char> middle;

            for (int i = left + 1; i < right; i++) {
                middle.insert(s[i]);
            }

            ans += middle.size();
        }

        return ans;
    }
};
