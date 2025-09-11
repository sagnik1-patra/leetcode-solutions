class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0, cur = 0;
        for (int x : nums) {
            if (x == 1) {
                cur++;
                maxLen = max(maxLen, cur);
            } else {
                cur = 0;
            }
        }
        return maxLen;
    }
};