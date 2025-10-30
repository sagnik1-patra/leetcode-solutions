class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int mark = s.size();
        
        // Traverse from right to left
        for (int i = s.size() - 1; i > 0; --i) {
            if (s[i - 1] > s[i]) {
                s[i - 1]--;
                mark = i; // all digits after i-1 must become 9
            }
        }
        
        for (int i = mark; i < s.size(); ++i)
            s[i] = '9';
        
        return stoi(s);
    }
};
