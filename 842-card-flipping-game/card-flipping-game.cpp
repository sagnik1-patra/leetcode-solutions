class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> bad; // numbers appearing on both sides of the same card
        int n = fronts.size();

        // Step 1: Identify all numbers that appear on both sides of the same card
        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i])
                bad.insert(fronts[i]);
        }

        int ans = INT_MAX;

        // Step 2: Check all front and back numbers; skip bad ones
        for (int i = 0; i < n; i++) {
            if (!bad.count(fronts[i])) ans = min(ans, fronts[i]);
            if (!bad.count(backs[i])) ans = min(ans, backs[i]);
        }

        // Step 3: Return result
        return ans == INT_MAX ? 0 : ans;
    }
};