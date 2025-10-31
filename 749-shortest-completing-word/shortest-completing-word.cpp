class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> freq(26, 0);

        // Step 1: Build frequency count for license plate letters
        for (char ch : licensePlate) {
            if (isalpha(ch)) {
                freq[tolower(ch) - 'a']++;
            }
        }

        string ans;
        int minLen = INT_MAX;

        // Step 2: Check each word
        for (string& word : words) {
            vector<int> cnt(26, 0);
            for (char c : word) cnt[c - 'a']++;

            bool valid = true;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] < freq[i]) {
                    valid = false;
                    break;
                }
            }

            // Step 3: Update shortest valid word
            if (valid && word.length() < minLen) {
                minLen = word.length();
                ans = word;
            }
        }

        return ans;
    }
};
