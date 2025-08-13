class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int write = 0; // next position to place a non-zero
        for (int read = 0; read < n; ++read) {
            if (nums[read] != 0) nums[write++] = nums[read];
        }
        while (write < n) nums[write++] = 0; // fill the rest with zeros
    }
};
