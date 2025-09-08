class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string out;
        out.reserve(s.size());

        int cnt = 0;
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            char c = s[i];
            if (c == '-') continue;
            if ('a' <= c && c <= 'z') c = char(c - 'a' + 'A');

            out.push_back(c);
            cnt++;
            if (cnt == k) {
                out.push_back('-');
                cnt = 0;
            }
        }

        // Remove trailing dash if any
        if (!out.empty() && out.back() == '-') out.pop_back();

        // Reverse to correct order
        reverse(out.begin(), out.end());
        return out;
    }
};