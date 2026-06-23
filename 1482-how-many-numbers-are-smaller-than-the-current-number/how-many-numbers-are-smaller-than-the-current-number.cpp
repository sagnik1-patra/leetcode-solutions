class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101, 0);
        
        // Step 1: count frequency
        for (int x : nums) {
            freq[x]++;
        }
        
        // Step 2: prefix sum
        for (int i = 1; i <= 100; i++) {
            freq[i] += freq[i - 1];
        }
        
        vector<int> res;
        
        // Step 3: build answer
        for (int x : nums) {
            if (x == 0) res.push_back(0);
            else res.push_back(freq[x - 1]);
        }
        
        return res;
    }
};