class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        
        for (int j = 0; j < n; j++) {
            int leftLess = 0, leftGreater = 0;
            int rightLess = 0, rightGreater = 0;
            
            // count left side
            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j]) leftLess++;
                else leftGreater++;
            }
            
            // count right side
            for (int k = j + 1; k < n; k++) {
                if (rating[k] > rating[j]) rightGreater++;
                else rightLess++;
            }
            
            // increasing + decreasing
            ans += leftLess * rightGreater;
            ans += leftGreater * rightLess;
        }
        
        return ans;
    }
};