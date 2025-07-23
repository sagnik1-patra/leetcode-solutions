class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& temp) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue; // Already used in current path
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue; // Skip duplicates

            used[i] = true;
            temp.push_back(nums[i]);

            backtrack(nums, used, temp);

            used[i] = false;
            temp.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        vector<bool> used(nums.size(), false);
        vector<int> temp;
        backtrack(nums, used, temp);
        return result;
    }
};
