class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> seen;

        for (string& w : words) {
            string even = "", odd = "";

            for (int i = 0; i < w.size(); i++) {
                if (i % 2 == 0)
                    even += w[i];
                else
                    odd += w[i];
            }

            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());

            // Create a unique signature
            string key = even + "|" + odd;
            seen.insert(key);
        }

        return seen.size();
    }
};
