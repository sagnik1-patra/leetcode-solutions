class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for (char c : num) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                --k;
            }
            st.push_back(c);
        }
        // remove remaining from the end
        while (k-- > 0 && !st.empty()) st.pop_back();

        // strip leading zeros
        int i = 0;
        while (i < (int)st.size() && st[i] == '0') ++i;
        string res = st.substr(i);
        return res.empty() ? "0" : res;
    }
};
