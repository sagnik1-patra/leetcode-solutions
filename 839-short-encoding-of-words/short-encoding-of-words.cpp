class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        // Step 1: Use unordered_set to store unique words
        unordered_set<string> st(words.begin(), words.end());

        // Step 2: Remove all suffixes that are also present as other words
        for (auto &w : words) {
            for (int i = 1; i < w.size(); i++) {
                st.erase(w.substr(i)); // remove any suffix
            }
        }

        // Step 3: The remaining words contribute to final encoding
        int ans = 0;
        for (auto &w : st) {
            ans += w.size() + 1; // +1 for '#'
        }

        return ans;
    }
};