class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        // Step 1: Count frequency of each number
        unordered_map<int, int> freq;
        
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Sort according to the given conditions
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            
            // Different frequencies:
            // smaller frequency comes first
            if (freq[a] != freq[b]) {
                return freq[a] < freq[b];
            }

            // Same frequency:
            // larger value comes first
            return a > b;
        });

        return nums;
    }
};