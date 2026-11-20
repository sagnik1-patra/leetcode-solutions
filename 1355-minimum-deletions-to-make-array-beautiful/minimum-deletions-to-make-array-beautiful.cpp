
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n - 1; i++) {

            if ((i - count) % 2 == 0 &&
                nums[i] == nums[i + 1]) {
                count++;
            }
        }

        if ((n - count) % 2 != 0) {
            count++;
        }

        return count;
    }
};
