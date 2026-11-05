
class Solution {
public:
    vector<string> findAllRecipes(
        vector<string>& recipes,
        vector<vector<string>>& ingredients,
        vector<string>& supplies
    ) {
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> indegree;

        int n = recipes.size();

        for (int i = 0; i < n; i++) {
            indegree[recipes[i]] = ingredients[i].size();

            for (string ing : ingredients[i]) {
                adj[ing].push_back(recipes[i]);
            }
        }

        queue<string> q;

        for (string s : supplies) {
            q.push(s);
        }

        vector<string> ans;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            for (string recipe : adj[curr]) {
                indegree[recipe]--;

                if (indegree[recipe] == 0) {
                    ans.push_back(recipe);
                    q.push(recipe);
                }
            }
        }

        return ans;
    }
};
