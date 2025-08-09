class Solution {
public:
    int computeLPS(string& str) {
        int n = str.size();
        vector<int> lps(n, 0);
        int len = 0;
        for (int i = 1; i < n; i++) {
            while (len > 0 && str[i] != str[len]) {
                len = lps[len - 1];
            }
            if (str[i] == str[len]) {
                len++;
                lps[i] = len;
            }
        }
        return lps[n - 1]; // longest prefix-suffix length
    }

    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string combined = s + "#" + rev_s;
        
        int pal_len = computeLPS(combined);
        
        string suffix = s.substr(pal_len);
        reverse(suffix.begin(), suffix.end());
        
        return suffix + s;
    }
};
