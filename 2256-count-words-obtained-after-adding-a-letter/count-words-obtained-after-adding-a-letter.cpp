
class Solution {
public:
    int wordCount(vector<string>& startWords,
                  vector<string>& targetWords) {

        unordered_set<int> st;

        // Step 1: Convert startWords into bitmasks
        for (string word : startWords) {
            int mask = 0;

            for (char c : word) {
                mask |= (1 << (c - 'a'));
            }

            st.insert(mask);
        }

        int ans = 0;

        // Step 2: Check each target word
        for (string word : targetWords) {
            int mask = 0;

            for (char c : word) {
                mask |= (1 << (c - 'a'));
            }

            // Remove each letter one by one
            for (char c : word) {
                int newMask = mask ^ (1 << (c - 'a'));

                if (st.count(newMask)) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};
