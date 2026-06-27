class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        int suffixSum = 0;
        int result = 0;
        
        for (int i = satisfaction.size() - 1; i >= 0; i--) {
            suffixSum += satisfaction[i];
            
            if (suffixSum > 0) {
                result += suffixSum;
            } else {
                break;
            }
        }
        
        return result;
    }
};