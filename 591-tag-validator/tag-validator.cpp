class Solution {
public:
    bool isValid(string code) {
        stack<string> st;
        int n = code.size();
        for (int i = 0; i < n; ) {
            // Rule 1: CDATA
            if (i > 0 && st.empty()) return false; // must be inside outer tag

            if (i + 9 < n && code.substr(i, 9) == "<![CDATA[") {
                int j = code.find("]]>", i + 9);
                if (j == string::npos) return false; // malformed CDATA
                i = j + 3;
            }
            else if (i + 2 < n && code.substr(i, 2) == "</") {
                int j = code.find(">", i + 2);
                if (j == string::npos) return false;
                string tag = code.substr(i + 2, j - (i + 2));
                if (!isValidTag(tag)) return false;
                if (st.empty() || st.top() != tag) return false;
                st.pop();
                i = j + 1;
                if (st.empty() && i < n) return false; // content after outermost close
            }
            else if (code[i] == '<') {
                int j = code.find(">", i + 1);
                if (j == string::npos) return false;
                string tag = code.substr(i + 1, j - (i + 1));
                if (!isValidTag(tag)) return false;
                st.push(tag);
                i = j + 1;
            }
            else {
                i++; // normal text
            }
        }
        return st.empty();
    }

private:
    bool isValidTag(const string& tag) {
        if (tag.empty() || tag.size() > 9) return false;
        for (char c : tag)
            if (c < 'A' || c > 'Z') return false;
        return true;
    }
};