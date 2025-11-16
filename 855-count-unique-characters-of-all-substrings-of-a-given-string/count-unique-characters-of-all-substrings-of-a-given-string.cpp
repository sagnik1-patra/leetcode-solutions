class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<vector<int>> idx(26); // store indices for each character
        
        for (int i = 0; i < 26; i++) {
            idx[i].push_back(-1); // add left boundary
        }

        for (int i = 0; i < n; i++) {
            idx[s[i] - 'A'].push_back(i);
        }

        for (int i = 0; i < 26; i++) {
            idx[i].push_back(n); // add right boundary
        }

        long long ans = 0;

        // Each character contributes based on its position between previous and next occurrence
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j < (int)idx[i].size() - 1; j++) {
                long long left = idx[i][j] - idx[i][j - 1];
                long long right = idx[i][j + 1] - idx[i][j];
                ans += left * right;
            }
        }

        return (int)ans;
    }
};