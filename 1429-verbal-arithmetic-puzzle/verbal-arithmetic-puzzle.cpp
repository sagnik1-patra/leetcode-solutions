class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        unordered_map<char, int> weight;
        unordered_set<char> leading;

        // Mark leading chars
        for (auto &w : words) {
            if (w.size() > 1) leading.insert(w[0]);
        }
        if (result.size() > 1) leading.insert(result[0]);

        // Build weights
        for (auto &w : words) {
            int p = 1;
            for (int i = w.size() - 1; i >= 0; i--) {
                weight[w[i]] += p;
                p *= 10;
            }
        }

        int p = 1;
        for (int i = result.size() - 1; i >= 0; i--) {
            weight[result[i]] -= p;
            p *= 10;
        }

        // Extract unique chars
        vector<char> chars;
        for (auto &it : weight) {
            if (it.second != 0)
                chars.push_back(it.first);
        }

        vector<bool> used(10, false);

        return backtrack(chars, 0, 0, weight, used, leading);
    }

    bool backtrack(vector<char>& chars, int idx, long long sum,
                   unordered_map<char, int>& weight,
                   vector<bool>& used,
                   unordered_set<char>& leading) {

        if (idx == chars.size()) {
            return sum == 0;
        }

        char ch = chars[idx];

        for (int d = 0; d <= 9; d++) {
            if (used[d]) continue;

            // No leading zero
            if (d == 0 && leading.count(ch)) continue;

            used[d] = true;

            if (backtrack(chars, idx + 1,
                          sum + weight[ch] * d,
                          weight, used, leading))
                return true;

            used[d] = false;
        }

        return false;
    }
};