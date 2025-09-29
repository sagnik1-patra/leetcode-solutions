class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstIndex; 
        firstIndex[0] = -1; // prefix sum 0 before starting
        int prefix = 0, maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix += (nums[i] == 1 ? 1 : -1);

            if (firstIndex.count(prefix)) {
                maxLen = max(maxLen, i - firstIndex[prefix]);
            } else {
                firstIndex[prefix] = i;
            }
        }
        return maxLen;
    }
};