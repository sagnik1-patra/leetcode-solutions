class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;

        int longest = 0;
        for (auto &p : freq) {
            int num = p.first;
            if (freq.count(num + 1)) {
                longest = max(longest, freq[num] + freq[num + 1]);
            }
        }
        return longest;
    }
};