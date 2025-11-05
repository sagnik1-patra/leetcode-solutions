class Solution {
public:
    string customSortString(string order, string s) {
        // Step 1: Count frequency of each character in s
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        string result;

        // Step 2: Add characters in the order defined by 'order'
        for (char c : order) {
            if (freq.count(c)) {
                result.append(freq[c], c);
                freq.erase(c);
            }
        }

        // Step 3: Add remaining characters (not in 'order') in any order
        for (auto &p : freq) {
            result.append(p.second, p.first);
        }

        return result;
    }
};