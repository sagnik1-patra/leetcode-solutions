class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }

private:
    void backtrack(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current); // Add current subset

        for (int i = index; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            backtrack(i + 1, nums, current, result); // Explore further
            current.pop_back(); // Backtrack
        }
    }
};
