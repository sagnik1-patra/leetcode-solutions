class Solution {
public:
    bool dfs(string &s, int index, unsigned long long previous) {
        
        // Entire string has been successfully used
        if (index == s.size()) {
            return true;
        }

        unsigned long long current = 0;

        for (int i = index; i < s.size(); i++) {

            // Build current number
            current = current * 10 + (s[i] - '0');

            // We need current = previous - 1
            if (previous > 0 && current == previous - 1) {
                
                if (dfs(s, i + 1, current)) {
                    return true;
                }
            }

            // Once current becomes too large,
            // adding more digits will not help
            if (previous == 0 || current >= previous) {
                break;
            }
        }

        return false;
    }

    bool splitString(string s) {
        int n = s.size();

        unsigned long long first = 0;

        // First number cannot consume the entire string
        for (int i = 0; i < n - 1; i++) {

            first = first * 10 + (s[i] - '0');

            if (dfs(s, i + 1, first)) {
                return true;
            }
        }

        return false;
    }
};