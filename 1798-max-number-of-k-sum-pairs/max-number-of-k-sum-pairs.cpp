class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int operations = 0;

        for (int num : nums) {
            int need = k - num;

            if (freq[need] > 0) {
                operations++;
                freq[need]--;
            } else {
                freq[num]++;
            }
        }

        return operations;
    }
};