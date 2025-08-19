class Solution {
public:
    string decodeString(string s) {
        string curr;                 // current built string at this level
        int num = 0;                 // current repeat count being parsed
        vector<pair<string,int>> st; // stack of (previous string, repeat)

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');   // build multi-digit k
            } else if (c == '[') {
                st.push_back({curr, num});    // save state
                curr.clear();
                num = 0;
            } else if (c == ']') {
                auto [prev, rep] = st.back(); st.pop_back();
                string tmp;
                tmp.reserve(curr.size() * rep);
                for (int i = 0; i < rep; ++i) tmp += curr;  // repeat
                curr = prev + tmp;                          // append to previous level
            } else {
                curr.push_back(c);          // normal character
            }
        }
        return curr;
    }
};
