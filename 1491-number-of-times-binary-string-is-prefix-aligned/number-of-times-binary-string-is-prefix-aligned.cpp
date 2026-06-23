class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int maxFlipped = 0;
        int count = 0;
        
        for (int i = 0; i < flips.size(); i++) {
            maxFlipped = max(maxFlipped, flips[i]);
            
            // i+1 because steps are 1-indexed
            if (maxFlipped == i + 1) {
                count++;
            }
        }
        
        return count;
    }
};