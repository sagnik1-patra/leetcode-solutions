class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int currSum = 0;
        
        vector<int> result;
        
        for (int x : nums) {
            currSum += x;
            result.push_back(x);
            
            if (currSum > totalSum - currSum) {
                break;
            }
        }
        
        return result;
    }
};