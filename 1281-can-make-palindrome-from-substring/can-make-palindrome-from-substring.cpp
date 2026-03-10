class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] ^ (1 << (s[i] - 'a'));
        }

        vector<bool> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2];

            int mask = prefix[r + 1] ^ prefix[l];
            int odd = __builtin_popcount(mask);

            ans.push_back(odd / 2 <= k);
        }

        return ans;
    }
};