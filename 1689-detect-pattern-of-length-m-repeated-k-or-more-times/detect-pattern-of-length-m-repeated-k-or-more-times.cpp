class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        
        for (int i = 0; i + m * k <= n; i++) {
            bool valid = true;
            
            for (int j = 0; j < m * (k - 1); j++) {
                if (arr[i + j] != arr[i + j + m]) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) return true;
        }
        
        return false;
    }
};