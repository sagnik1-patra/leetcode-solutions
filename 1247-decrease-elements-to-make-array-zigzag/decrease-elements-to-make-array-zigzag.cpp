class Solution {
public:
    int moves(vector<int>& nums, int valleyParity) {
        int n = nums.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == valleyParity) {
                int left = (i > 0) ? nums[i - 1] : INT_MAX;
                int right = (i + 1 < n) ? nums[i + 1] : INT_MAX;

                int minNeighbor = min(left, right);
                if (nums[i] >= minNeighbor) {
                    res += nums[i] - (minNeighbor - 1);
                }
            }
        }
        return res;
    }

    int movesToMakeZigzag(vector<int>& nums) {
        // Case 1: even indices are valleys
        int evenValley = moves(nums, 0);

        // Case 2: odd indices are valleys
        int oddValley = moves(nums, 1);

        return min(evenValley, oddValley);
    }
};
