
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();
        int start = 0;

        for (int j = 0; j < n; j++) {
            if (nums[j] == key) {
                int left = max(start, j - k);
                int right = min(n - 1, j + k);

                for (int i = left; i <= right; i++) {
                    ans.push_back(i);
                }

                start = right + 1;
            }
        }

        return ans;
    }
};
