class Solution {
public:
    unordered_map<string, int> memo;

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs);
    }

    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int> needs) {
        // encode state as string key
        string key;
        for (int n : needs) key += to_string(n) + ",";

        if (memo.count(key)) return memo[key];

        // base cost (no special offer)
        int minCost = 0;
        for (int i = 0; i < needs.size(); ++i)
            minCost += needs[i] * price[i];

        // try each special offer
        for (auto& offer : special) {
            vector<int> nextNeeds = needs;
            bool valid = true;
            for (int i = 0; i < needs.size(); ++i) {
                if (nextNeeds[i] < offer[i]) { // invalid offer (exceeds need)
                    valid = false;
                    break;
                }
                nextNeeds[i] -= offer[i];
            }
            if (valid) {
                minCost = min(minCost, offer.back() + dfs(price, special, nextNeeds));
            }
        }

        return memo[key] = minCost;
    }
};
