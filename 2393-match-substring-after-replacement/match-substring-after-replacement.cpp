class Solution {
public:
    bool matchReplacement(string s, string sub,
                          vector<vector<char>>& mappings) {

        bool mp[128][128] = {};

        for (auto& m : mappings) {
            mp[m[0]][m[1]] = true;
        }

        int n = s.size();
        int m = sub.size();

        for (int i = 0; i <= n - m; i++) {

            bool valid = true;

            for (int j = 0; j < m; j++) {

                if (s[i + j] != sub[j] &&
                    !mp[sub[j]][s[i + j]]) {

                    valid = false;
                    break;
                }
            }

            if (valid)
                return true;
        }

        return false;
    }
};