class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int left = 1, right = n;

        // Alternate between smallest and largest to create distinct differences
        while (left <= right) {
            if (k > 1) {
                if (k % 2 == 1) ans.push_back(left++);
                else ans.push_back(right--);
                k--;
            } else {
                ans.push_back(left++);
            }
        }

        return ans;
    }
};
