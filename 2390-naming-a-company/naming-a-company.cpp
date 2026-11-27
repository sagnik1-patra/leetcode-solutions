class Solution {
public:
    long long distinctNames(vector<string>& ideas) {

        vector<unordered_set<string>> groups(26);

        // Group strings by their first character
        for (auto& idea : ideas) {
            groups[idea[0] - 'a'].insert(idea.substr(1));
        }

        long long ans = 0;

        // Compare every pair of groups
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {

                long long common = 0;

                // Count common suffixes
                for (auto& suffix : groups[i]) {
                    if (groups[j].count(suffix)) {
                        common++;
                    }
                }

                long long a = groups[i].size() - common;
                long long b = groups[j].size() - common;

                ans += 2 * a * b;
            }
        }

        return ans;
    }
};