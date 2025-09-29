class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderIndex;
        remainderIndex[0] = -1; // remainder 0 before starting

        long long prefix = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            int rem = prefix % k;

            if (remainderIndex.count(rem)) {
                if (i - remainderIndex[rem] >= 2) {
                    return true;
                }
            } else {
                remainderIndex[rem] = i; // store earliest occurrence
            }
        }
        return false;
    }
};