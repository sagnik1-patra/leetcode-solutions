class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> used(26, false);

        // Count frequency
        for (char c : s) {
            freq[c - 'a']++;
        }

        string stack;

        for (char c : s) {
            int idx = c - 'a';
            freq[idx]--;

            if (used[idx]) continue;

            while (!stack.empty() &&
                   stack.back() > c &&
                   freq[stack.back() - 'a'] > 0) {
                used[stack.back() - 'a'] = false;
                stack.pop_back();
            }

            stack.push_back(c);
            used[idx] = true;
        }

        return stack;
    }
};
