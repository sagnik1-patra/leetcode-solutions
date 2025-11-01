class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int count = 0, start = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') count++;
            else count--;

            if (count == 0) {
                // recursively process the inside
                string inner = s.substr(start + 1, i - start - 1);
                parts.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }

        // sort parts in reverse lex order to get largest string
        sort(parts.rbegin(), parts.rend());

        string result;
        for (auto &p : parts) result += p;
        return result;
    }
};
