class Solution {
public:
    string toLowerCase(string s) {
        for (char &c : s) {
            if (c >= 'A' && c <= 'Z')
                c = c - 'A' + 'a';  // convert to lowercase
        }
        return s;
    }
};
