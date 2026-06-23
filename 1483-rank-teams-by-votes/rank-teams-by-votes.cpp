class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes[0].size();
        
        // Step 1: count votes
        unordered_map<char, vector<int>> mp;
        
        for (char c : votes[0]) {
            mp[c] = vector<int>(n, 0);
        }
        
        for (auto& vote : votes) {
            for (int i = 0; i < n; i++) {
                mp[vote[i]][i]++;
            }
        }
        
        // Step 2: collect teams
        vector<char> teams(votes[0].begin(), votes[0].end());
        
        // Step 3: sort
        sort(teams.begin(), teams.end(), [&](char a, char b) {
            for (int i = 0; i < n; i++) {
                if (mp[a][i] != mp[b][i]) {
                    return mp[a][i] > mp[b][i]; // more votes first
                }
            }
            return a < b; // lexicographical tie-break
        });
        
        // Step 4: build result
        string res = "";
        for (char c : teams) res += c;
        
        return res;
    }
};