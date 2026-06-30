class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        
        // -------- MAX --------
        string a = s;
        for (char c : a) {
            if (c != '9') {
                char x = c;
                for (char &ch : a) {
                    if (ch == x) ch = '9';
                }
                break;
            }
        }
        
        // -------- MIN --------
        string b = s;
        if (b[0] != '1') {
            char x = b[0];
            for (char &ch : b) {
                if (ch == x) ch = '1';
            }
        } else {
            for (int i = 1; i < b.size(); i++) {
                if (b[i] != '0' && b[i] != '1') {
                    char x = b[i];
                    for (char &ch : b) {
                        if (ch == x) ch = '0';
                    }
                    break;
                }
            }
        }
        
        return stoi(a) - stoi(b);
    }
};