class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToIndex;
        unordered_map<string, string> emailToName;
        int idx = 0;

        // Step 1: Map each email to an index and name
        for (auto& acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); ++i) {
                string email = acc[i];
                if (!emailToIndex.count(email)) {
                    emailToIndex[email] = idx++;
                    emailToName[email] = name;
                }
            }
        }

        parent.resize(idx);
        iota(parent.begin(), parent.end(), 0);

        // Step 2: Union all emails in the same account
        for (auto& acc : accounts) {
            int first = emailToIndex[acc[1]];
            for (int i = 2; i < acc.size(); ++i) {
                unite(first, emailToIndex[acc[i]]);
            }
        }

        // Step 3: Group emails by root parent
        unordered_map<int, vector<string>> groups;
        for (auto& [email, i] : emailToIndex) {
            groups[find(i)].push_back(email);
        }

        // Step 4: Sort and build the final result
        vector<vector<string>> res;
        for (auto& [root, emails] : groups) {
            sort(emails.begin(), emails.end());
            string name = emailToName[emails[0]];
            emails.insert(emails.begin(), name);
            res.push_back(emails);
        }

        return res;
    }
};
