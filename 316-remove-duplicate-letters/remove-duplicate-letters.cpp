class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, -1);
        for (int i = 0; i < (int)s.size(); ++i) last[s[i]-'a'] = i;

        string st;                  // acts as a monotonic stack
        vector<bool> in(26, false); // whether a char is already in stack

        for (int i = 0; i < (int)s.size(); ++i) {
            char c = s[i];
            if (in[c-'a']) continue; // already included

            // Maintain lexicographically smallest by popping bigger chars
            while (!st.empty() && c < st.back() && last[st.back()-'a'] > i) {
                in[st.back()-'a'] = false;
                st.pop_back();
            }
            st.push_back(c);
            in[c-'a'] = true;
        }
        return st;
    }
};
