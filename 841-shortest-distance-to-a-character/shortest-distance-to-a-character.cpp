class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n, n); // initialize with large value

        int prev = -n; // left-to-right pass
        for (int i = 0; i < n; i++) {
            if (s[i] == c) prev = i;
            ans[i] = i - prev;
        }

        prev = 2 * n; // right-to-left pass
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) prev = i;
            ans[i] = min(ans[i], prev - i);
        }

        return ans;
    }
};