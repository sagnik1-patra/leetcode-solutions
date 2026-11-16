
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);

        int left = 0, right = n - 1;

        for (int x : nums) {
            if (x < pivot) {
                ans[left++] = x;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > pivot) {
                ans[right--] = nums[i];
            }
        }

        while (left <= right) {
            ans[left++] = pivot;
        }

        return ans;
    }
};
