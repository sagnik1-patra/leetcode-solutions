class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;

        int needed = 1 << k;

        for (int i = 0; i + k <= s.size(); i++) {
            st.insert(s.substr(i, k));

            if (st.size() == needed) {
                return true;
            }
        }

        return false;
    }
};