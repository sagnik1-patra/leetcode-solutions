
class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        string st = "";
        int remaining = count(s.begin(), s.end(), letter);
        int required = repetition;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            while (!st.empty() && st.back() > ch &&
                   (int)st.size() - 1 + (n - i) >= k &&
                   (st.back() != letter || remaining > required)) {

                char removed = st.back();
                st.pop_back();

                if (removed == letter) {
                    required++;
                }
            }

            if ((int)st.size() < k) {
                if (ch == letter) {
                    st.push_back(ch);
                    required--;
                }
                else if (k - (int)st.size() > required) {
                    st.push_back(ch);
                }
            }

            if (ch == letter) {
                remaining--;
            }
        }

        return st;
    }
};
