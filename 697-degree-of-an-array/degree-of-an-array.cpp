class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count, first, last;
        
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            if (!first.count(x)) first[x] = i;
            last[x] = i;
            count[x]++;
        }
        
        int degree = 0, minLen = nums.size();
        for (auto& [num, freq] : count)
            degree = max(degree, freq);
        
        for (auto& [num, freq] : count) {
            if (freq == degree)
                minLen = min(minLen, last[num] - first[num] + 1);
        }
        
        return minLen;
    }
};
