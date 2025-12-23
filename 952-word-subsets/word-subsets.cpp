class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> req(26, 0);

        // Step 1: Build max frequency requirement from words2
        for (string& b : words2) {
            vector<int> cnt(26, 0);
            for (char c : b) cnt[c - 'a']++;
            for (int i = 0; i < 26; i++)
                req[i] = max(req[i], cnt[i]);
        }

        vector<string> result;

        // Step 2: Check each word in words1
        for (string& a : words1) {
            vector<int> cnt(26, 0);
            for (char c : a) cnt[c - 'a']++;

            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] < req[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok) result.push_back(a);
        }

        return result;
    }
};
