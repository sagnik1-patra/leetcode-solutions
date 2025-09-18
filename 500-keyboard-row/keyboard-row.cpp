class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // Map each letter to its keyboard row (0,1,2)
        int row[26];
        string r1 = "qwertyuiop", r2 = "asdfghjkl", r3 = "zxcvbnm";
        for (char c : r1) row[c - 'a'] = 0;
        for (char c : r2) row[c - 'a'] = 1;
        for (char c : r3) row[c - 'a'] = 2;

        vector<string> ans;
        for (const string& w : words) {
            int target = -1;
            bool ok = true;
            for (char ch : w) {
                char c = tolower(ch);
                if (target == -1) target = row[c - 'a'];
                else if (row[c - 'a'] != target) { ok = false; break; }
            }
            if (ok) ans.push_back(w);
        }
        return ans;
    }
};
