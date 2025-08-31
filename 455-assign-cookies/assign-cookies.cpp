class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, cnt = 0;
        while (i < (int)g.size() && j < (int)s.size()) {
            if (s[j] >= g[i]) { // cookie j satisfies child i
                ++cnt; ++i; ++j;
            } else {
                ++j;            // try a bigger cookie
            }
        }
        return cnt;
    }
};
