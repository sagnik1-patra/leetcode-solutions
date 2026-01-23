class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                       vector<vector<string>>& people) {
        int n = req_skills.size();
        unordered_map<string, int> skillId;

        // Map each skill to a bit
        for (int i = 0; i < n; i++) {
            skillId[req_skills[i]] = i;
        }

        // Convert each person to a skill bitmask
        int m = people.size();
        vector<int> personMask(m, 0);
        for (int i = 0; i < m; i++) {
            for (auto& s : people[i]) {
                personMask[i] |= (1 << skillId[s]);
            }
        }

        int FULL = (1 << n) - 1;

        // dp[mask] = smallest team achieving mask
        vector<vector<int>> dp(1 << n);
        for (int i = 1; i <= FULL; i++) dp[i] = vector<int>(1000);

        dp[0] = {};

        for (int i = 0; i < m; i++) {
            int pMask = personMask[i];
            for (int mask = 0; mask <= FULL; mask++) {
                if (dp[mask].size() >= 1000) continue;

                int newMask = mask | pMask;
                if (dp[newMask].size() > dp[mask].size() + 1) {
                    dp[newMask] = dp[mask];
                    dp[newMask].push_back(i);
                }
            }
        }

        return dp[FULL];
    }
};
