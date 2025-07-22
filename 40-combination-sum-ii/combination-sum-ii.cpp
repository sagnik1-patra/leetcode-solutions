class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current); // Found a valid combination
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break; // No need to proceed further
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, current, result); // i+1 because we can't reuse same element
            current.pop_back(); // Backtrack
        }
    }
};
