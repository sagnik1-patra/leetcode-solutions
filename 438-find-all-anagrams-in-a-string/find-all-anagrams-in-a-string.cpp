class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (n < m) return {};

        int need[26] = {0}, win[26] = {0};
        for (char c : p) need[c - 'a']++;

        // initialize first window [0..m-1]
        for (int i = 0; i < m; ++i) win[s[i] - 'a']++;

        int matches = 0;
        for (int c = 0; c < 26; ++c)
            if (need[c] == win[c]) matches++;

        vector<int> ans;
        if (matches == 26) ans.push_back(0);

        for (int l = 0, r = m; r < n; ++l, ++r) {
            int inC = s[r] - 'a';
            int outC = s[l] - 'a';

            // add incoming char
            if (win[inC] == need[inC]) matches--;     // will diverge
            win[inC]++;
            if (win[inC] == need[inC]) matches++;     // maybe re-align

            // remove outgoing char
            if (win[outC] == need[outC]) matches--;   // will diverge
            win[outC]--;
            if (win[outC] == need[outC]) matches++;   // maybe re-align

            if (matches == 26) ans.push_back(l + 1);
        }
        return ans;
    }
};
