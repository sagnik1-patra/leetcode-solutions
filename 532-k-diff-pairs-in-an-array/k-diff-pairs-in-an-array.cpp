class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0; // difference cannot be negative

        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;

        int count = 0;
        for (auto& [num, f] : freq) {
            if (k == 0) {
                if (f > 1) count++;
            } else {
                if (freq.count(num + k)) count++;
            }
        }
        return count;
    }
};