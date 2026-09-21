class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        
        int m = languages.size();

        // Store languages known by each user
        vector<unordered_set<int>> known(m + 1);

        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                known[i + 1].insert(lang);
            }
        }

        // Users involved in friendships where
        // they cannot currently communicate
        unordered_set<int> needTeaching;

        for (auto& f : friendships) {
            int u = f[0];
            int v = f[1];

            bool canCommunicate = false;

            for (int lang : known[u]) {
                if (known[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }

            if (!canCommunicate) {
                needTeaching.insert(u);
                needTeaching.insert(v);
            }
        }

        // If everyone can already communicate
        if (needTeaching.empty()) {
            return 0;
        }

        int answer = needTeaching.size();

        // Try teaching each possible language
        for (int lang = 1; lang <= n; lang++) {
            int teachCount = 0;

            for (int user : needTeaching) {
                if (!known[user].count(lang)) {
                    teachCount++;
                }
            }

            answer = min(answer, teachCount);
        }

        return answer;
    }
};